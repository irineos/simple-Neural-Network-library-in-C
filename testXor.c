#include "nn.h"

int main(){

	Network n;
	loadModel(&n, "xorModel.txt");
	int networkSize = n.numberOfLayers;

	//(0,0)->0
	//(0,1)->1
	//(1,0)->1
	//(1,1)->0
	double testInput[][2] = {{0.0,0.0},{0.0,1.0},{1.0,0.0},{1.0,1.0}};
	
	for(int i=0;i<4;i++){
		forwardPass(&n,testInput[i]);
		double prediction = n.layer[networkSize-1].node[0].value;
		printf("input: (%d,%d) === prediction: %lf\n",(int)testInput[i][0],(int)testInput[i][1],prediction);
	}


}