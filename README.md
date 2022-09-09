
# Speech based Tutorial for Children

In this application, we implemented an Speech based Tutorial system which helps Children to recognized different fruits and vegitables.
We have set of 20 fruits and vegitables images. Children first learn these from Tutorial module. then they can test their learning in "Quiz module".
There is one more section of "Live Tranining" Where Children can add new word in the dictionary by Tranining the model by 20 utterence of the new word 
and learn how to pronounce that. 


## Experimental setup

This project is divided into following modules:

    (1) Live Training Module

    (2) Quiz for children

    (3) Tutorial Module



**(1) Training Module**

The flow for training over data is as follows:

  i.   Record the data as 20 utterance of each word

  ii.  Extract frames for every utterance

  iii. Get the observation sequence

  iv.  Generate the model for this word

  v.   And keep this model with the already created models

  vi.  Ask the user to  give his utterance for testing
 
  vii. Then testing will start and the predicted word will be shown.



**2. Quiz for children**

10 random images for fruits or vegetables will be shown and the child has to guess the correct 
answer to the image by speaking the name of the image. 
The utterance will be recorded and the observation sequence will be generated for each utterance and then for each observation sequence 
all the models will be run and which ever model  gives the maximum score  for the word will be selected as the required model.



**3.Tutorial Module**

For the tutorial  we have the images and below it we have the description for the given images.

## Screenshots

**1) App UI**

![first](https://user-images.githubusercontent.com/37476399/189272243-b664ad21-85f3-4e72-a30e-3605d0fc5078.PNG)

**2) Tutorial UI**

![second](https://user-images.githubusercontent.com/37476399/189272273-5af18b78-fbf5-4763-8792-d00d37a3d2a5.PNG)

**3) Quiz UI**

![third](https://user-images.githubusercontent.com/37476399/189272407-d5ec546a-7ab9-494c-ac74-546eb4c4f2c6.PNG)

**4) Result UI**

![4](https://user-images.githubusercontent.com/37476399/189272521-6283c5d8-36f9-4b2a-ad37-923d40852cfb.PNG)

**5) Live Training Module UI**

![last](https://user-images.githubusercontent.com/37476399/189272460-494e6b63-710c-4d01-87bd-6b28cfdcea9c.PNG)


## Project Demo

[demo.zip](https://github.com/dhruvil16/Speech-Based-Tutorial-For-Children/files/9532363/demo.zip)


