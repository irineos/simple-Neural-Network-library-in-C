#include "nn.h"

int main(){
	
	Network net;
	//network architecture (2 inputs, 1 hidden layer with 4 neurons and 1 output)
	int nlayerSizes[] = {2,4,1}; 
	int networkSize = LENGTH(nlayerSizes);
	//activation functions for hidden and output layers
	char* activationFunc[] = {"tanh","tanh"};

	initNetwork(&net,networkSize, nlayerSizes, activationFunc);
	randomizeWeights(&net);

	//xor gate truth table
	double input[][2] = {{0.0,0.0},{0.0,1.0},{1.0,0.0},{1.0,1.0}};
	double target[][2] = {{0.0},  {1.0},  {1.0},  {0.0}};
	
	
	double learningRate = 0.1f;
	
	for(int epochs=0;epochs<500;epochs++){
		printf("==========  Epoch %d  ==========\n",epochs+1);
		for(int i=0;i<4;i++){
			forwardPass(&net,input[i]);
			backProp(&net,target[i]);
			updateWeights(&net,learningRate);

			double mserror = mse(net,target[i]);
			printf("%lf\n",mserror);
		}
	}
	
	saveModel(&net,"xorModel.txt");
}