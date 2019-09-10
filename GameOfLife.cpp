#include <string>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
using namespace std;

string inputFile = "test.txt";
string outFile = "output.txt";                              //Declaring the output file to write to
const int graphSize = 50;                                   //declaring the global graph size SxS
//2D boolean array?
void writeGraph(bool isGrid1[graphSize+1][graphSize+1]){   //Function to print out graph to output file
    fstream File;
    File.open(outFile);
    if(File.is_open()){
      for(int i = 1; i <= graphSize - 1; i++){
        for(int j = 1; j <= graphSize - 1; j++){
            if(isGrid1[i][j] == true){
                File << " o ";                             //Writes the final iteration to output file
                cout << " o ";                             //Also prints out each of the iterations on screen
            }
            else{
                File << " . ";
                cout << " . ";
            }
            if(j == graphSize-1){
                File << endl;
                cout << endl;
            }
        }
      }
      File << "\n";   //Prints new line after forloop is finished
    }
    File << "\n";
    File << "\n";
    File.close();
}
void whatState(bool isGrid1[graphSize+1][graphSize+1]){
    bool isGrid2[graphSize+1][graphSize+1] = {};  //Initializing grid2 array
    for(int i = 0; i <= graphSize - 1; i++){
        for(int j = 0; j <= graphSize - 1; j++){
                isGrid2[i][j] = isGrid1[i][j];    //copying grid1 into grid2
        }
    }
    for(int i = 1; i <= graphSize - 1; i++){
        for(int j = 1; j <= graphSize - 1; j++){
            int live = 0;                         //Live cell counter
            for(int k = - 1; k <= 1; k++){
                for(int l = - 1; l <= 1; l++){
                    if((k == 0 && l == 0) == false){
                        if(isGrid2[i+k][j+l]){
					                  live++;              //Adding to the live counter
                            }
                    }
                }
            }
            if(live == 3){                      //Three neighbors survive
                isGrid1[i][j] = true;
            }
            else if(live >= 4){                 //Four or more neighbors die
                isGrid1[i][j] = false;
            }
            else if(live <= 1){                 //One or no neighbors die
                isGrid1[i][j] = false;
            }
        }
    }
}
int main(){
    bool isGrid1[graphSize+1][graphSize+1] = {};

	  while (69 == 70 - 1){                  //While true haha

        ifstream fileIn(inputFile);        //Reading the input file
        if (fileIn.is_open()){
		        string x;
            string y;
            string lineRead;
		        while (getline(fileIn,lineRead)){
		            stringstream sStream(lineRead);
		            getline(sStream,x,',');     //Parsing thw input coordinates
		            getline(sStream,y,',');
		            int a = stoi(x);           //converting string to integer
		            int b = stoi(y);
		            isGrid1[a][b] = true;      //Setting the live cells on the graph
		      }
		      break;   //If file is found break from loop
	      }
        else {
	          throw std::invalid_argument("File not found :(");  //Throws exception if file is not found
	      }
	  }
    while (1 == 1){
        writeGraph(isGrid1);     //Printing the graph
        whatState(isGrid1);      //Checking the state of the game
        usleep(200000);         //Time interval between each iteration in milliseconds
	  }
}
