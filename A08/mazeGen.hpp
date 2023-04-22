#include<iostream>
#include <vector>
using namespace std;
typedef pair<int, int> Point;

void Assignment08::createMazeMesh(int row, int col, char **maze) {
	// The procedure gets in input the number of rows <row> of the maze, and the number of columns <col>
	// Element <maze[r][c]>, with 0 <= r <= row-1 and 0 <= c <= col-1 contains:
	//		Symbol ' ' if there is an empty space
	//		Symbol '#' if there is a wall
	//
	// Example: The following piece of code executes the instruction in the ... section
	//          if there is a wall in position r=5, c=7
	//
	// int r, c;
	// r = 5; c = 7;
	// if(maze[r][c] == '#') {
	//		...
	// }
	//
	// The example below creates a square, with four vertices and two triangles.
	// It must be deleted and replaced with your code creating the mesh of the maze.
    


    
    int idxCount = 0;
    int vrtx[row+1][col+1];
    
   
    for(int i = 0; i < row+1; i++){
        for(int j = 0; j < col+1; j++){
            vrtx[i][j] = 0;
            
        }
    }
    
    //#########################################################################################
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            
            if(maze[i][j] == '#'){
                
                if(vrtx[i][j]==0){
                    vrtx[i][j] = 1;
                } else {
                    vrtx[i][j] = 0;
                }
                
                if(vrtx[i+1][j]==0){
                    vrtx[i+1][j] = 1;
                } else {
                    vrtx[i+1][j] = 0;
                }
                
                if(vrtx[i][j+1]==0){
                    vrtx[i][j+1] = 1;
                } else {
                    vrtx[i][j+1] = 0;
                }
                
                if(vrtx[i+1][j+1]==0){
                    vrtx[i+1][j+1] = 1;
                } else {
                    vrtx[i+1][j+1] = 0;
                }
                
            }
            
        }
    }
    
    
    for(int i=0;i<row+1;++i){
            for(int j=0;j<col+1;++j){
                cout<<vrtx[i][j]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;

    //#########################################################################################
    
    
    int idx = 1;
    int bufflen = 0;
    
    for(int i = 0; i < row+1; i++){
        for(int j = 0; j < col+1; j++){
            
            if(vrtx[i][j]==1){
                vrtx[i][j] = idx;
                idx+=2;
                
                vPos.push_back(i); vPos.push_back(0.0); vPos.push_back(j);
                vPos.push_back(i); vPos.push_back(1); vPos.push_back(j);
                
                bufflen += 1;
            }
            
            if(bufflen == 2){
                bufflen = 0;
                
                vIdx.push_back(idxCount); vIdx.push_back(idxCount+1); vIdx.push_back(idxCount+2);
                vIdx.push_back(idxCount+1); vIdx.push_back(idxCount+2); vIdx.push_back(idxCount+3);
                
                idxCount += 4;
                
            }
            
        }
    }
    
    int idxBuff=0;
    
    for(int i = 0; i < row+1; i++){
        for(int j = 0; j < col+1; j++){
            
            if(vrtx[j][i]!=0){
                
                if(bufflen == 1){
                    bufflen = 0;
                    
                    vIdx.push_back(idxBuff-1); vIdx.push_back(idxBuff+1-1); vIdx.push_back(vrtx[j][i]-1);
                    vIdx.push_back(vrtx[j][i]+1-1); vIdx.push_back(vrtx[j][i]-1); vIdx.push_back(idxBuff+1-1);
                    
                } else {
                    bufflen += 1;
                }
                
                idxBuff = vrtx[j][i];
            }
            
        }
    }
    


    // Fill the array vIdx with the indices of the vertices of the triangles
    vIdx.push_back(vrtx[0][0]-1); vIdx.push_back(vrtx[0][col]-1); vIdx.push_back(vrtx[row][0]-1);    // First triangle
    vIdx.push_back(vrtx[0][col]-1); vIdx.push_back(vrtx[row][0]-1); vIdx.push_back(vrtx[row][col]-1);    // Second triangle
	
    //Horizontal ceiling
    int tmp1 = -1;
    int tmp2 = -1;
    int v1 = 0;
    int v2 = 0;
    
    
    for (int r = 0; r<row; r++){
        for (int c = 0; c<col; c++){
            if(c == 0){
                if(maze[r][c+1] == '#'){
                    if(vrtx[r][c] != 0) tmp1 = vrtx[r][c] ;
                    else tmp1 = vrtx[r][c+1] ;
                    if(vrtx[r+1][c] != 0) tmp2 = vrtx[r+1][c] ;
                    else tmp2 = vrtx[r+1][c+1] ;
                    
                }
            }else if (maze[r][c] == '#' && maze[r][c+1] == '#'){
                if(tmp1 < 0 && tmp2 < 0){
                    if(vrtx[r][c] != 0) tmp1 = vrtx[r][c];
                    else tmp1 = vrtx[r][c+1];
                    if(vrtx[r+1][c] != 0) tmp2 = vrtx[r+1][c];
                    else tmp2 = vrtx[r+1][c+1];
                }
            } else if ((maze[r][c] == '#' && maze[r][c+1] == ' ') || c == col-1){
                if(maze[r][c-1] == '#'){
                    if(vrtx[r][c] != 0) v1 = vrtx[r][c];
                    else v1 = vrtx[r][c+1];
                    if(vrtx[r+1][c] != 0) v2 = vrtx[r+1][c];
                    else v2 = vrtx[r+1][c+1];
                    
                    vIdx.push_back(tmp1); vIdx.push_back(v1); vIdx.push_back(v2);
                    vIdx.push_back(tmp1); vIdx.push_back(tmp2); vIdx.push_back(v2);
                    
                    tmp1 = -1;
                    tmp2 = -1;
                }
            }
        }
    }
    
    
    tmp1= -1;
    tmp2= -1;
    v1=0;
    v2=0;
    
    for (int c = 0; c<col; c++){
        for (int r = 0; r<row; r++){
            if(r == 0){
                if(tmp1 < 0 && tmp2 < 0 && maze[r+1][c] == '#'){
                    if(vrtx[r][c] != 0) tmp1 = vrtx[r][c];
                    else tmp1 = vrtx[r+1][c];
                    if(vrtx[r][c+1] != 0) tmp2 = vrtx[r][c+1];
                    else tmp2 = vrtx[r+1][c+1];
                }
            } else if(r==row-1){
                if(maze[r-1][c]=='#'){
                    if(vrtx[r][c] != 0) v1 = vrtx[r][c];
                    else v1 = vrtx[r+1][c];
                    if(vrtx[r][c+1] != 0) v2 = vrtx[r][c+1];
                    else v2 = vrtx[r+1][c+1];
                    
                    vIdx.push_back(tmp1); vIdx.push_back(v1); vIdx.push_back(v2);
                    vIdx.push_back(tmp1); vIdx.push_back(tmp2); vIdx.push_back(v2);
                    
                    tmp1 = -1;
                    tmp2 = -1;
                }
            } else {
                if(maze[r][c]=='#' && maze[r+1][c]=='#'){
                    if(tmp1<0 && tmp2<0){
                        if(vrtx[r][c] != 0) tmp1 = vrtx[r][c];
                        else tmp1 = vrtx[r+1][c];
                        if(vrtx[r][c+1] != 0) tmp2 = vrtx[r][c+1];
                        else tmp2 = vrtx[r+1][c+1];
                    }
                }else if(maze[r][c]=='#' && maze[r+1][c]==' '){
                    if(maze[r-1][c]=='#'){
                        if(vrtx[r][c] != 0) v1 = vrtx[r][c];
                        else v1 = vrtx[r+1][c];
                        if(vrtx[r][c+1] != 0) v2 = vrtx[r][c+1];
                        else v2 = vrtx[r+1][c+1];
                        
                        vIdx.push_back(tmp1); vIdx.push_back(v1); vIdx.push_back(v2);
                        vIdx.push_back(tmp1); vIdx.push_back(tmp2); vIdx.push_back(v2);
                        
                        tmp1=-1;
                        tmp2=-1;
                    }
                }
            }
        }
    }
    
    
    
    
	
}

