// HMM_Assignment.cpp : Defines the entry point for the console application.
//
#include "stdlib.h"
#include "math.h"
#include "string"
#include "StdAfx.h"
#define NO_OF_SAMPLES_PER_FRAME 320																	// Defines no of frames
#define P 12																	// Defines parameter P 
#define NORAMLIZED_FILE_PATH "Temp/normalized_sample.txt"						// Temporary file path used for storing normalized samples
#define DC_REMOVED_FILE_PATH "Temp/temp_dc_shift_removed.txt"					// Temporary file path used for storing dc shift removed samples
#define Temp_Energy_cal_FILE_PATH "Temp/temp_calculation_file.txt"				// Temporary file for calculating and storing energy of a frames
#define NUMBER_OF_SAMPLE_FOR_DC_SHIFT 2000										// NO of initial samples which are used for dc shift calculation
#define NORMALIZATION_FACTOR 5000												// Defines Normalization Factor 
#define PI 3.14																	// Defines PI value
#define PREFIX_OF_FILE_NAME "214101028_"										// Stores the prefix of recording txt file 
#define NO_OF_DIGITS 20															// Stores the No of vowels
#define NO_OF_TRAINING_FILE_PER_DIGIT 20										// Stores the no of files used for training a vowel
#define NO_OF_TESTING_FILE_PER_DIGIT 10
#define CODEBOOK_SIZE 32
#define INITIAL_A_MATRIX_PATH "initial_lambda/A_initial.txt"
#define INITIAL_B_MATRIX_PATH "initial_lambda/B_initial.txt"
#define INITIAL_PI_MATRIX_PATH "initial_lambda/pi_initial.txt"

#define LIVE_TESTING_FILE_NAME "testing.txt"
#define LIVE_TESTING_OBSERVATION_FILE_NAME "testing_observation_seq.txt"
#define LIVE_DATA_OBSERVATION_SEQ_PATH "live_data_obs_seq.txt"

// HMM Parameter
#define N 5
#define M 32
#define T 150

static int T_cur = 0;
static long double THRESHOLD = 0;
static long double A[N+1][N+1],cum_A[N+1][N+1];
static long double B[N+1][M+1],cum_B[N+1][M+1];
static long double pi[N+1],cum_pi[N+1];
static int observation[T+1];
static long double alpha[N+1][T+1];
static long double beta[N+1][T+1];
static long double gama[N+1][T+1];
static long double zeta[N+1][N+1][T+1];
static long double delta[N+1][T+1];
static int sai[N+1][T+1];
static char* mapping[21] = {
	"mango","apple","banana","guava","kiwi","watermelon","grape","lemon","strawberry","orange","potato",
"tomato","corn","carrot","garlic","pea","eggplant","onion","chilli","spinach","Live"
};

static double TOKHURA_WEIGHT[] = {1.0, 3.0, 7.0, 13.0, 19.0, 22.0, 25.0, 33.0, 42.0, 50.0, 56.0, 61.0};	// Predefined TOKHURA weights
static double* list_frames;
static double codebook[CODEBOOK_SIZE][12];




void static readCodebook(){
	FILE* fp = fopen("codebook.txt","r");
	
	for(int i = 0; i < CODEBOOK_SIZE; i++)
	{
		for(int j = 0; j < 12; j++)
		{
			fscanf(fp,"%lf",&(codebook[i][j]));
		}
	}
	fclose(fp);
}

long int static generate_frames(){
	int total_frames = 0;
	double temp = 0,sample_val = 0,energy = 0,max_energy=0;
	long int start_marker = 1,counter = 1,index = 0;
	
	FILE* fp = fopen(NORAMLIZED_FILE_PATH,"r");
	FILE* energy_fp = fopen(Temp_Energy_cal_FILE_PATH,"w");
	

	// Calculate the energy for all frames and store it in a file
	while(!feof(fp))
	{
		energy = 0;
		for(int i=0;i < NO_OF_SAMPLES_PER_FRAME;i++)
		{
			fscanf(fp,"%lf",&sample_val);
			temp = (sample_val * sample_val) / NO_OF_SAMPLES_PER_FRAME;
			energy = energy + temp;
		}
		total_frames++;
		fprintf(energy_fp,"%lf\n",energy);
	}
	fclose(energy_fp);
	rewind(fp);

	energy_fp = fopen(Temp_Energy_cal_FILE_PATH,"r");
	
	fscanf(energy_fp,"%lf",&max_energy);
	
	// Find the frame having max energy and start markekr in terms of energy value 
	while(!feof(energy_fp))
	{
		fscanf(energy_fp,"%lf",&temp);
		counter++;
		if(temp > max_energy)
		{
			start_marker = counter; 
			max_energy = temp;
		}
	}
	fclose(energy_fp);


	int frames_after_current = total_frames - start_marker;
	int no_of_frames_under_considration = (int)(0.8 * start_marker) + (int)(0.8 * frames_after_current);
	
	if(no_of_frames_under_considration >= 150)
	{
		if(start_marker > 80)
		{
			start_marker = start_marker - 50;
		}else{
			start_marker = start_marker - (int)(0.8 * start_marker);;
		}
		no_of_frames_under_considration = 100;
	}else{
			start_marker = start_marker - (int)(0.8 * start_marker);		
	}
	counter = 0;
	while(!feof(fp))
	{
		if(counter == start_marker)
			break;
		fscanf(fp,"%lf",&temp);
		counter++;
	}

	list_frames = (double*)malloc(no_of_frames_under_considration * NO_OF_SAMPLES_PER_FRAME * sizeof(double));

	// Store all 5 steady frames into the array
	for(int i=0; i < NO_OF_SAMPLES_PER_FRAME * no_of_frames_under_considration && !feof(fp);i++)
	{
		fscanf(fp,"%lf",&temp);
		list_frames[i] = temp;
	}

	fclose(fp);
	return no_of_frames_under_considration;
	
}


/*
	This function will compute the R values from the 320 sample frame. 
*/
void static calculate_R_values(double sample[NO_OF_SAMPLES_PER_FRAME],double *R)
{
	double temp1,temp2;
	int i;
	for(i=0;i<=P;i++)
	{
		temp1 = 0;
		for(int j = 0 ;j < NO_OF_SAMPLES_PER_FRAME-i;j++)
		{
			temp1 += (sample[j] * sample[j+i]);
		}
		R[i] = temp1 ;
	}
}

/*
	This function will compute the A values from the Ri values
*/
void static calculate_A_values(double R[],double* A){
	double E[ NO_OF_SAMPLES_PER_FRAME + 1 ],alpha[P+1][P+1],K[P+1];
	int i;
	double temp1;
	E[0] = R[0];
	for(i = 1; i <= P; i++)
	{
		temp1 = 0;
		for(int j = 1 ; j <= i-1; j++)
			temp1 += (alpha[j][i-1] * R[i-j]);	
		K[i] = (R[i] - temp1)/E[i-1];
		alpha[i][i] = K[i];

		for(int j = 1; j <= i-1; j++ )
		{
			alpha[j][i] = alpha[j][i-1] - (K[i] * alpha[i-j][i-1]);		
		}
		E[i] = (1 - K[i] * K[i])*E[i-1];

	}
	for(int j=1;j<=P;j++)
	{
		A[j] = alpha[j][P];
 	}
}

/*
	This function will compute cepstral coefficients from the Ai and Ri values and store it in array C
*/
void static calculate_C_values(double A[],double R[],double* C){
	double temp1;
	C[0] = log(R[0]*R[0]);
	for(int i=1;i<=P;i++)
	{
		temp1 = 0;

		for(int j = 1 ; j<= i-1; j++)
		{
			temp1 += (( j * C[j] * A[i-j]) / i );
		}
		C[i] = A[i] + temp1;
	}

}


/*
	This function will calculate the DC shift value from the file whos path is passed as argument of the function.
	For DC shift calculation this will consider "NUMBER_OF_SAMPLE_FOR_DC_SHIFT"(i.e here 2000) this many initial samples.  
*/
double static calculate_dc_shift(char file_path[])
{
	int sample_val;
	double sum = 0;
	int count = 0;
	FILE* fp = fopen(file_path,"r");

	// calculate the sum of 2000 samples
	while(!feof(fp))
	{
		fscanf(fp,"%d\n", &sample_val);
		count++;
		sum += abs(sample_val);
		if(count == NUMBER_OF_SAMPLE_FOR_DC_SHIFT)
			break;
	}
	fclose(fp);
	return (sum/NUMBER_OF_SAMPLE_FOR_DC_SHIFT);
}

/*
	This function will perform Normalization on the samples from which DC shift is removed.
	Normalization factor that is used is 5000.
	Normalized samples are stored in this path "Training/normalized_sample.txt"
*/
void static normalization_of_file(char* file_path)
{
	FILE* dc_shift_removed_fp = fopen(file_path,"r");
	FILE* normalized_sample_fp = fopen(NORAMLIZED_FILE_PATH,"w");
		
	double max_val,temp,nor_val;
	fscanf(dc_shift_removed_fp,"%lf",&max_val);
	max_val =  abs(max_val);

	// Find the max absolute sample value
	while(!feof(dc_shift_removed_fp))
	{
		fscanf(dc_shift_removed_fp,"%lf",&temp);
		if(max_val < abs(temp))
				max_val = abs(temp);
	}
	rewind(dc_shift_removed_fp);
	
	// Normalize all the samples with NF = 5000 
	while(!feof(dc_shift_removed_fp))
	{
		fscanf(dc_shift_removed_fp,"%lf",&temp);

		nor_val = (temp * NORMALIZATION_FACTOR /max_val);

		fprintf(normalized_sample_fp,"%lf\n",nor_val);
		
	}
	fclose(dc_shift_removed_fp);
	fclose(normalized_sample_fp);
} 

/*
	This will compute the sine window and multiply it with C values and store back to C array.
*/
void static sine_window_on_C_values(double * C)
{
	double w = 0;
	for(int m = 1; m <= P ; m++)
	{
		w = 1 + 6 * sin((PI * m)/12);
		C[m] = C[m] * w;
	}
}

int static find_codebook_index(double C[13])
{
	double dist = 0;
	double min_dist = 0;
	int index = 1;
	double temp = 0;
	for(int j = 0; j < 12; j++)
	{
		temp = codebook[0][j] - C[j+1];
		min_dist += (TOKHURA_WEIGHT[j] * temp * temp);
	}
		
	for(int i = 1; i < CODEBOOK_SIZE; i++)
	{
		dist = 0;
		for(int j = 0; j < 12; j++)
		{
			temp = codebook[i][j] - C[j+1];
			dist += (TOKHURA_WEIGHT[j] * temp * temp);
		}
		if(dist < min_dist)
		{
			min_dist = dist;
			index = i+1;
		}
	}
	return index;
}

void static generate_observation_sequence_for_live_data()
{
	double temp1;
	double dc_shift_val = 0;													// Stores the dc shift values
	char file_number[3];																																													
	char file_path[60];															// Stores the path of file which is under considratoin.

	double sample[NO_OF_SAMPLES_PER_FRAME],sum = 0;										
	int base;
													// Points to the ref file of avg Ci values

	double R[P+1],A[P+1],C[P+1];												// Stores Ri Ai and Ci values
	
	char observation_file_path[60] = LIVE_DATA_OBSERVATION_SEQ_PATH;
	char digit_no[3];
	
	FILE* observation_seq_fp = fopen(observation_file_path,"w");

	// read codebook
	readCodebook();

	int no_of_frames_under_considration = 0;
		
	for(int j = 0 ; j < 20 ;j++)
	{
		// Generating the file path dynamically.
		strcpy(file_path,"test_utterence/");
		sprintf(digit_no,"%d",j);
		strcat(file_path, digit_no);
		strcat(file_path, ".txt");

		// Calculate DC shift
		dc_shift_val = calculate_dc_shift(file_path);
		
		FILE* digit_file_fp = fopen(file_path,"r");
		FILE* digit_dc_shift_val_fp = fopen(DC_REMOVED_FILE_PATH,"w");
			
		while(!feof(digit_file_fp))
		{
			fscanf(digit_file_fp,"%lf",&temp1);
			fprintf(digit_dc_shift_val_fp,"%lf\n",temp1 - dc_shift_val);
		}

		fclose(digit_file_fp);
		fclose(digit_dc_shift_val_fp);

		// Perfrom Normalization with NF = 5000
		normalization_of_file(DC_REMOVED_FILE_PATH);
			
		// Generate steady frames
		no_of_frames_under_considration = generate_frames();

		for(int k = 0 ; k < no_of_frames_under_considration ;k++)
		{
			base = NO_OF_SAMPLES_PER_FRAME * k; 
			for(int m = 0; m < NO_OF_SAMPLES_PER_FRAME ; m++)
			{
				sample[m] = list_frames[base + m];
			}

			calculate_R_values(sample, R);					// Calcuate the Ri values

			calculate_A_values(R,A);						// Calculate the Ai values

			calculate_C_values(A,R,C);						// Calculate the Ci values

			sine_window_on_C_values(C);						// Apply raised Sine window in Ci values 

			int index = find_codebook_index(C);
				
			fprintf(observation_seq_fp,"%d	",index);
		}
		fprintf(observation_seq_fp,"%d",-1);				// append -1 to find end of sequence
		fprintf(observation_seq_fp,"\n");
		free(list_frames);
	}
	fclose(observation_seq_fp);
}

void static generate_observation_sequence(){
	double temp1;
	double dc_shift_val = 0;													// Stores the dc shift values
	char file_number[3];																																													
	char file_path[60];															// Stores the path of file which is under considratoin.

	double sample[NO_OF_SAMPLES_PER_FRAME],sum = 0;										
	int base;
													// Points to the ref file of avg Ci values

	double R[P+1],A[P+1],C[P+1];												// Stores Ri Ai and Ci values
	
	char observation_file_path[60] = "obs.txt";
	char digit_no[3];
	
	FILE* observation_seq_fp = fopen(observation_file_path,"w");

	// read codebook
	readCodebook();

	int no_of_frames_under_considration = 0;
		
	for(int j = 0 ; j < 10 ;j++)
	{
		// Generating the file path dynamically.
		strcpy(file_path,"recording/");
		sprintf(digit_no,"%d",j);
		strcat(file_path, digit_no);
		strcat(file_path, ".txt");

		// Calculate DC shift
		dc_shift_val = calculate_dc_shift(file_path);
		
		FILE* digit_file_fp = fopen(file_path,"r");
		FILE* digit_dc_shift_val_fp = fopen(DC_REMOVED_FILE_PATH,"w");
			
		while(!feof(digit_file_fp))
		{
			fscanf(digit_file_fp,"%lf",&temp1);
			fprintf(digit_dc_shift_val_fp,"%lf\n",temp1 - dc_shift_val);
		}

		fclose(digit_file_fp);
		fclose(digit_dc_shift_val_fp);

		// Perfrom Normalization with NF = 5000
		normalization_of_file(DC_REMOVED_FILE_PATH);
			
		// Generate steady frames
		no_of_frames_under_considration = generate_frames();

		for(int k = 0 ; k < no_of_frames_under_considration ;k++)
		{
			base = NO_OF_SAMPLES_PER_FRAME * k; 
			for(int m = 0; m < NO_OF_SAMPLES_PER_FRAME ; m++)
			{
				sample[m] = list_frames[base + m];
			}

			calculate_R_values(sample, R);					// Calcuate the Ri values

			calculate_A_values(R,A);						// Calculate the Ai values

			calculate_C_values(A,R,C);						// Calculate the Ci values

			sine_window_on_C_values(C);						// Apply raised Sine window in Ci values 

			int index = find_codebook_index(C);
				
			fprintf(observation_seq_fp,"%d	",index);
		}
		fprintf(observation_seq_fp,"%d",-1);				// append -1 to find end of sequence
		fprintf(observation_seq_fp,"\n");
		free(list_frames);
	}
	fclose(observation_seq_fp);
	
}

// HMM functions
long double static viterbi()
{
	int index = 1;
	long double temp1 = 0;
	long double temp2 = 0;
	int q_star[T + 1];
	long double p_star = 0;
	printf("\n\n---------State Sequence----------------\n\n");
	// Initialization
	for(int i = 1; i <= N; i++)
	{
		delta[i][1] = pi[i] * (B[i][observation[1]]);
		sai[i][1] = 0;
	}

	// Recursion
	for(int t = 2; t <= T_cur; t++)
	{
		for(int j = 1; j <= N; j++)
		{
			for(int i = 1; i <= N; i++)
			{
				if(i == 1)
				{
					temp1 = delta[i][t-1] * A[i][j];
					temp2 = temp1 * B[j][observation[t]];
					index = 1;
				}
				else
				{
					if(temp1 < delta[i][t-1] * A[i][j])
					{
						index = i;
						temp1 = delta[i][t-1] * A[i][j];
					}
					if(temp2 < delta[i][t-1] * A[i][j] * B[j][observation[t]])
					{
						temp2 = delta[i][t-1] * A[i][j] * B[j][observation[t]];
					}
				}
			}
			delta[j][t] = temp2;
			sai[j][t] = index;
		}
	}

	// Termination
	temp1 = delta[1][T_cur];
	index = 1;

	for(int i = 2; i <= N; i++)
	{
		if(temp1 < delta[i][T_cur])
		{
			temp1 = delta[i][T_cur];
			index = i;
		}
	}
	p_star = temp1;
	q_star[T_cur] = index;

	// backtrack for seq of states
	for(int t = T_cur - 1; t > 0; t--)
	{
		q_star[t] = sai[q_star[t+1]][t+1];
	}

	printf("\nP* : %g\n\n",p_star);
	
	for(int i = 1; i <= T_cur; i++)
	{
		printf(" %d ",q_star[i]);
	}
	printf("\n\n");
	return p_star;
}

void static make_A_stocastic(long double A[N+1][N+1]){
	long double sum = 0,max = 0;
	int index = 0;
	for(int i = 1; i <= N; i++)
	{
		sum = 0;
		for(int j = 1; j <= N ; j++)
		{
			if(j == 1)
			{
				max = A[i][j];
				index = j;
			}
			else
			{
				if(A[i][j] > max)
				{
					max = A[i][j];
					index = j;
				}
			}
			sum += A[i][j];  
		}
		A[i][index] = A[i][index] + (1-sum);
	}
}

void static make_B_stocastic(long double B[N+1][M+1]){
	long double sum = 0,max = 0;
	int index = 0;
	for(int i = 1; i <= N; i++)
	{
		sum = 0;
		for(int j = 1; j <= M ; j++)
		{
			if(j == 1)
			{
				max = B[i][j];
				index = j;
			}
			else
			{
				if(B[i][j] > max)
				{
					max = B[i][j];
					index = j;
				}
			}
			sum += B[i][j];  
		}
		B[i][index] = B[i][index] + (1-sum);
	}
}

void static compute_new_lambda(){
	long double numerator = 0, denominator = 0;
	// Recompute PI
	for(int i = 1; i <= N; i++)
	{
		pi[i] = gama[i][1];
	}

	//Recompute A
	for(int i = 1; i <= N; i++)	
	{
		denominator = 0;
		for(int k = 1; k <= T_cur; k++ )
		{
			denominator = denominator + gama[i][k];
		}

		for(int j = 1; j <= N; j++)
		{
			numerator = 0;
			for(int k = 1; k <= T_cur; k++)
			{
				numerator = numerator + zeta[i][j][k];
			}
			A[i][j] = numerator / denominator;
		}
	}
	make_A_stocastic(A);
	// Recompute B

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			numerator = denominator = 0;
			for(int t = 1; t <= T_cur; t++)
			{
				if(observation[t] == j)
				{
					numerator = numerator + gama[i][t];
				}
				denominator = denominator + gama[i][t];
			}
			B[i][j] = numerator / denominator;
			if(B[i][j] == 0)
			{
				B[i][j] = 1e-30;
			}
		}
	}
	make_B_stocastic(B);
}

long double static calculate_alpha(){
	for(int i = 1; i <= N; i++)
		alpha[i][1] = pi[i] * B[i][observation[1]];
	
	long double sum = 0;
	
	for(int t = 1; t < T_cur; t++)
	{
		for(int j = 1; j <= N; j++)
		{
			sum = 0;
			for(int i = 1; i <= N; i++)
			{
				sum = sum + alpha[i][t] * A[i][j];
			}
			alpha[j][t+1] = sum * B[j][observation[t+1]];
		}
	}
	
	sum = 0;
	for(int i = 1; i <= N ; i++)
	{
		sum = sum + alpha[i][T_cur];
	}

	return sum;
}

void static calculate_beta(){
	long double sum = 0;
	for(int i = 1; i <= N; i++)
	{
		beta[i][T_cur] = 1;
	}

	for(int t = T_cur-1; t > 0; t--)
	{
		for(int i = 1; i <= N; i++)
		{
			sum = 0;
			for(int j = 1; j <= N; j++)
			{
				sum = sum + (A[i][j] * B[j][observation[t+1]] * beta[j][t+1]);
			}
			beta[i][t] = sum;
		}
	}
}

void static calculate_gama(){
	long double sum = 0;
	for(int t = 1; t <= T_cur; t++)
	{
		for(int i = 1 ; i <= N; i++)
		{
			sum = 0;
			for(int j = 1; j <= N; j++)
			{
				sum = sum + zeta[i][j][t];
			}
			gama[i][t] = sum;
		}
	}

}

void static calculate_zeta()
{
	long double sum = 0;

	for(int t = 1; t < T_cur; t++)
	{
		sum = 0;
		for(int p = 1; p <= N; p++)
		{
			for(int q = 1; q <= N; q++)
			{
				sum = sum + (alpha[p][t] * A[p][q] * B[q][observation[t+1]] * beta[q][t+1]);
			}
		}

		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				zeta[i][j][t] = ( alpha[i][t] * A[i][j] * B[j][observation[t+1]] * beta[j][t+1] ) / sum;
			}
		}
	}
}

void static print_converged_A_B_PI(){
	printf("\n\n-----------A-----------\n\n");
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N ; j++)
		{
			printf("%g ",cum_A[i][j]);
		}
		printf("\n");
	}

	printf("\n\n-----------B-----------\n\n");
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M ; j++)
		{
			printf("%g ",cum_B[i][j]);
		}
		printf("\n\n");
	}

	for(int i = 1; i <= N; i++)
	{
		printf("%g ",cum_pi[i]);
	}
}

void static print_A(){
	printf("\n\n-----------A-----------\n\n");
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N ; j++)
		{
			printf("%g ",A[i][j]);
		}
		printf("\n");
	}
}

void static print_B(){
	printf("\n\n-----------B-----------\n\n");
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M ; j++)
		{
			printf("%g ",B[i][j]);
		}
		printf("\n\n");
	}
}

void static print_pi(){
	for(int i = 1; i <= N; i++)
	{
		printf("%g ",pi[i]);
	}
}

void static read_A(char file_path[60])
{
	FILE* fp = fopen(file_path,"r");
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			fscanf(fp,"%Lf",&A[i][j]);
		}
	}
	fclose(fp);
}

void static read_B(char file_path[60])
{
	FILE* fp;
	fp = fopen(file_path,"r");
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			fscanf(fp,"%Lf",&B[i][j]);
		}
	}

	fclose(fp);
}

void static read_PI(char file_path[60]){
	FILE* fp = fopen(file_path,"r");
	for(int i = 1; i <= N; i++)
		fscanf(fp,"%Lf",&pi[i]);
	fclose(fp);
}

void static print_alpha(){
	printf("\n\n------------------Alpha--------------------------\n\n");
	for(int i = 1; i <= T_cur; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			printf(" %g  ",alpha[j][i]);
		}
		printf("\n\n");
	}
}

void static print_beta(){
	printf("\n\n---------------Beta----------------------\n\n");
	for(int i = 1; i <= T_cur; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			printf("%g  ",beta[j][i]);
		}
		printf("\n\n");
	}
}

void static print_zeta(){
	for(int i = 1; i <= T_cur; i++)
	{
		printf("t = %d \n",i);
		for(int j = 1; j <= N; j++)
		{
			for(int k = 1; k <= N; k++)
			{
				printf("%g  ",zeta[j][k][i]);
			}
			printf("\n");
		}	
		printf("\n\n");
	}
}

void static print_gama(){
	printf("\n\n----------------Gama---------------------\n\n");
	for(int i = 1; i <= T_cur; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			printf("%g  ",gama[j][i]);
		}
		printf("\n\n");
	}
}

void static find_avg_A_B_PI(){
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N ; j++)
		{
			cum_A[i][j] /= NO_OF_TRAINING_FILE_PER_DIGIT;
		}
	}

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M ; j++)
		{
			cum_B[i][j] /= NO_OF_TRAINING_FILE_PER_DIGIT;
		}
	}

	for(int i = 1; i <= N; i++)
	{
		cum_pi[i] /= NO_OF_TRAINING_FILE_PER_DIGIT; 
	}

}

void static cumulate_A_B_PI(){
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N ; j++)
		{
			cum_A[i][j] += A[i][j];
		}
	}

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M ; j++)
		{
			cum_B[i][j] += B[i][j];
		}
	}

	for(int i = 1; i <= N; i++)
	{
		cum_pi[i] += pi[i]; 
	}
}

void static clear_cum_A_B_PI(){

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N ; j++)
		{
			cum_A[i][j] = 0;
		}
	}

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M ; j++)
		{
			cum_B[i][j] = 0;
		}
	}

	for(int i = 1; i <= N; i++)
	{
		cum_pi[i] = 0;
	}
}

bool static store_model_on_file(int digit){
	
	FILE* fp;

	char model_file_path[30];
	strcpy(model_file_path,"Live_Model/A_");
	strcat(model_file_path, mapping[digit]);
	strcat(model_file_path, ".txt");
	fp = fopen(model_file_path,"w");

	if(fp == NULL)
		return false;

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N ; j++)
		{
			fprintf(fp,"%g	",cum_A[i][j]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
	
	strcpy(model_file_path,"Live_Model/B_");
	strcat(model_file_path, mapping[digit]);
	strcat(model_file_path, ".txt");
	fp = fopen(model_file_path,"w");
	
	if(fp == NULL)
		return false;
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M ; j++)
		{
			fprintf(fp,"%g	",cum_B[i][j]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
	
	strcpy(model_file_path,"Live_Model/PI_");
	strcat(model_file_path, mapping[digit]);
	strcat(model_file_path, ".txt");
	fp = fopen(model_file_path,"w");

	if(fp == NULL)
		return false;

	for(int i = 1; i <= N; i++)
	{
		fprintf(fp,"%g ",cum_pi[i]);
	}

	fclose(fp);
	return true;
}

bool static train_model(int digit)
{
	char file_number[5];
	int obs;
	int counter = 0;
	FILE* fp = fopen(LIVE_DATA_OBSERVATION_SEQ_PATH,"r");//opening of observation sequence file
	if(fp == NULL)
		return false;
		
	clear_cum_A_B_PI();

	for(int i = 0; i < 20; i++)
	{
		read_A(INITIAL_A_MATRIX_PATH);
		read_B(INITIAL_B_MATRIX_PATH);
		read_PI(INITIAL_PI_MATRIX_PATH);

		counter = 0;
		
		fscanf(fp,"%d",&obs);
		
		while(obs != -1)
		{
			observation[counter+1] = obs;
			fscanf(fp,"%d",&obs);
			counter++;
		}

		T_cur = counter;
		
		long double new_p_star = 0;

		long double old_p_star = 0;
		
		old_p_star = viterbi();

		for(int j = 0; j < 150; j++)
		{
			printf("itreation %d :\n\n",j+1);
			calculate_alpha();
			calculate_beta();
			calculate_zeta();
			calculate_gama();

			compute_new_lambda();

			new_p_star = viterbi();
			
			if(abs(new_p_star - old_p_star ) <= THRESHOLD)
				break;
			old_p_star = new_p_star;
		}
		cumulate_A_B_PI();
	}

	find_avg_A_B_PI();
	
	fclose(fp);
	
	store_model_on_file(digit);
	
	return true;
}

int static predict_digit(int observation[T+1]){
	char file_path[60];
	char file_number[5];

	int digit = 0;
	long double max_prob = 0,temp;
	
	printf("\n P(o|lambda) = [  ");

	for(int i = 0; i < NO_OF_DIGITS ; i++)
	{
		strcpy(file_path,"Model/");
		strcat(file_path, "A_"); 
		strcat(file_path, mapping[i]);
		strcat(file_path, ".txt");
		
		read_A(file_path);
		
		strcpy(file_path,"Model/");
		strcat(file_path, "B_"); 

		strcat(file_path, mapping[i]);
		strcat(file_path, ".txt");

		read_B(file_path);
		
		strcpy(file_path,"Model/");
		strcat(file_path, "PI_"); 

		strcat(file_path, mapping[i]);
		strcat(file_path, ".txt");

		read_PI(file_path);

		temp = calculate_alpha();

		printf("%g  ",temp);
		if(i == 0)
		{
			max_prob = temp;
			digit = 0;
		}else
		{
			if(temp > max_prob)
			{
				max_prob = temp;
				digit = i;
			}
		}
	}
	printf(" ]\n\n");
	return digit;
}

void static seq_live_test_observation(){
	double temp1;
	double dc_shift_val = 0;													// Stores the dc shift values
	char file_number[3];																																													

	double sample[NO_OF_SAMPLES_PER_FRAME],sum = 0;										
	int base;
													// Points to the ref file of avg Ci values

	double R[P+1],A[P+1],C[P+1];												// Stores Ri Ai and Ci values
	
	char observation_file_path[60] =  "Live_Data_Test/observation_seq.txt";

	char file_path[60] = "Live_Data_Test/test.txt";															// Stores the path of file which is under considratoin.

	FILE* observation_seq_fp = fopen(observation_file_path,"w");

	// read codebook
	readCodebook();

	int no_of_frames_under_considration = 0;	

	// Calculate DC shift
	dc_shift_val = calculate_dc_shift(file_path);
		
	FILE* digit_file_fp = fopen(file_path,"r");
	FILE* digit_dc_shift_val_fp = fopen(DC_REMOVED_FILE_PATH,"w");
			
	while(!feof(digit_file_fp))
	{
		fscanf(digit_file_fp,"%lf",&temp1);
		fprintf(digit_dc_shift_val_fp,"%lf\n",temp1 - dc_shift_val);
	}

	fclose(digit_file_fp);
	fclose(digit_dc_shift_val_fp);

	// Perfrom Normalization with NF = 5000
	normalization_of_file(DC_REMOVED_FILE_PATH);
			
	// Generate steady frames
	no_of_frames_under_considration = generate_frames();

	for(int k = 0 ; k < no_of_frames_under_considration ;k++)
	{
		base = NO_OF_SAMPLES_PER_FRAME * k; 
		for(int m = 0; m < NO_OF_SAMPLES_PER_FRAME ; m++)
		{
			sample[m] = list_frames[base + m];
		}

		calculate_R_values(sample, R);					// Calcuate the Ri values

		calculate_A_values(R,A);						// Calculate the Ai values

		calculate_C_values(A,R,C);						// Calculate the Ci values

		sine_window_on_C_values(C);						// Apply raised Sine window in Ci values 

		int index = find_codebook_index(C);
				
		fprintf(observation_seq_fp,"%d	",index);
	}
	fprintf(observation_seq_fp,"%d",-1);				// append -1 to find end of sequence
	fprintf(observation_seq_fp,"\n");
	free(list_frames);
	fclose(observation_seq_fp);
}

int static predict_digit_for_live_data(int observation[T+1]){
	char file_path[60];
	char file_number[5];

	int digit = 0;
	long double max_prob = 0,temp;
	
	printf("\n P(o|lambda) = [  ");

	for(int i = 0; i < NO_OF_DIGITS + 1 ; i++)
	{
		strcpy(file_path,"Live_Model/");
		strcat(file_path, "A_"); 
		strcat(file_path, mapping[i]);
		strcat(file_path, ".txt");
		
		read_A(file_path);
		
		strcpy(file_path,"Live_Model/");
		strcat(file_path, "B_"); 

		strcat(file_path, mapping[i]);
		strcat(file_path, ".txt");

		read_B(file_path);
		
		strcpy(file_path,"Live_Model/");
		strcat(file_path, "PI_"); 

		strcat(file_path, mapping[i]);
		strcat(file_path, ".txt");

		read_PI(file_path);

		temp = calculate_alpha();

		printf("%g  ",temp);
		if(i == 0)
		{
			max_prob = temp;
			digit = 0;
		}else
		{
			if(temp > max_prob)
			{
				max_prob = temp;
				digit = i;
			}
		}
	}
	printf(" ]\n\n");
	return digit;
}

static int* model_testing_using_static_data(){
	FILE* fp;
	int predicted_digit;
	int counter = 0;
	int obs = 0;
	int correct_prediction = 0;

	int* result = (int*)malloc(sizeof(int) * 10);

	char file_path[60] = "obs.txt"; 

	fp = fopen(file_path,"r");

	for(int j = 0; j < 10; j++)
	{
		counter = 0;
		obs = 0;
		fscanf(fp,"%d",&obs);
		
		while(obs != -1)
		{
			observation[counter+1] = obs;
			fscanf(fp,"%d",&obs);
		
			counter++;
		}
		T_cur = counter;	

		predicted_digit = predict_digit(observation);
		result[j] = predicted_digit;

	}	
	return result;
}

int static model_testing_using_live_data(){
	
	//FILE* fp;
	int predicted_digit;
	int counter = 0;
	int obs = 0;
	int correct_prediction = 0;

	char file_path[60] = "Live_Data_Test/observation_seq.txt"; 

	FILE *fp = fopen(file_path,"r");


	counter = 0;
	obs = 0;
	fscanf(fp,"%d",&obs);
		
	while(obs != -1)
	{
		observation[counter+1] = obs;
		fscanf(fp,"%d",&obs);
		counter++;
	}

	T_cur = counter;	

	predicted_digit = predict_digit_for_live_data(observation);
	
	return predicted_digit;
	}

bool static is_trained_model_available(){
		FILE* fp = fopen("Model/A_0.txt","r");
		if(fp == NULL)
		{
			return false;			
		}
		fclose(fp);
		return true;
}



/*
bool is_trained_model_available();
void model_testing_using_live_data();
void model_testing_using_static_data();
int predict_digit(int observation[T+1]);
bool train_model(int digit);
bool store_model_on_file(char file_number[5]);
void clear_cum_A_B_PI();
void cumulate_A_B_PI();
void find_avg_A_B_PI();
void print_gama();
void print_zeta();
void print_beta();
void print_alpha();
void read_PI(char file_path[60]);
void read_B(char file_path[60]);
void read_A(char file_path[60]);
void print_pi();
void print_B();
void print_A();
void print_converged_A_B_PI();
void calculate_zeta();
void calculate_gama();
void calculate_beta();
long double calculate_alpha();
void compute_new_lambda();
void make_B_stocastic(long double B[N+1][M+1]);
void make_A_stocastic(long double A[N+1][N+1]);
void generate_observation_sequence();
long double viterbi();
void generate_observation_sequence_for_live_data();
int find_codebook_index(double C[13]);
void sine_window_on_C_values(double * C);
void normalization_of_file(char* file_path);
double calculate_dc_shift(char file_path[]);
void calculate_C_values(double A[],double R[],double* C);
void calculate_A_values(double R[],double* A);
void calculate_R_values(double sample[NO_OF_SAMPLES_PER_FRAME],double *R);
long int generate_frames();
void readCodebook();
*/

