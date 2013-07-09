#include<stdio.h>

#define max(x, y) (((x) > (y)) ? (x) : (y))
//********************************************************************************************************************

int main() {
	int num_elements=7;

	//printf("%d",num_elements);


	int current_max = 0;
	int f[4];
	int h[4];

	f[0] = 0; // one indexing
	f[1] = 1;
	f[2] = 2;
	f[3] = 3;
	//f[4] = 3;
	//f[5] = 4;

	  //printf("Enter n: ");
	  //scanf("%d",&n);
	  //Links=(struct Slink*)malloc(num_elements*sizeof(struct Slink));
	 /* Above statement allocates the memory for n structures with pointer ptr pointing to base address */

	/*for(i=1;i<=num_elements;i++)
		{
		f[i]=(Link[i])->N1;  // Link[i].N1;
		h[i]=(Link[i])->N2;
		}
	*/

	h[0] = 0; //one indexing
	h[1] = 2;
	h[2] = 3;
	h[3] = 1;
	//h[4] = 4;
	//h[5] = 2;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	int i=0;
	int x[num_elements];// zero indexing
	int y[num_elements];//zero indexing
	int f_size = sizeof(f)/sizeof(f[0]);
	int h_size = sizeof(h)/sizeof(h[0]);

	for(i=1;i<f_size;i++)
	{
		x[i]=f[i];
		y[i]=h[i];


	}

int temp_size = f_size ;

	x[temp_size]=4;
	y[temp_size]=1;
	temp_size++;
	x[temp_size]=4;
	y[temp_size]=3;
	temp_size++;
	x[temp_size]=2;
	y[temp_size]=4;

for(i=1;i<=num_elements-1;i++)
{
	printf("\nx[%d] is:%d",i,x[i]);
	printf("\ny[%d] is:%d",i,y[i]);
}
int x_size = sizeof(x)/sizeof(x[0]);
int y_size = sizeof(y)/sizeof(y[0]);

printf(" The size of the x vector is %d \n",x_size);
printf(" The size of the y vector is %d \n",y_size);

if(x_size == y_size){

// The number of elements in the vectors
int n_ele = x_size-1;


current_max = max_array(x,n_ele);
printf("The max of x vector is %d \n", current_max);

fcircuit(x,y,n_ele);
//fcircuit(Slinks *Link[num_elements] , int num_elements);
} else{
printf(" The dimensions of the x and y vector do not match \n");
}


return 0;

}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	/*
	int f_size = sizeof(f)/sizeof(f[0]);
	int h_size = sizeof(h)/sizeof(h[0]);

	printf(" The size of the f vector is %d \n",f_size);
	printf(" The size of the h vector is %d \n",h_size);

	if(f_size == h_size){

	// The number of elements in the vectors
	int n_ele = f_size-1;


	current_max = max_array(f,n_ele);
	printf("The max of f vector is %d \n", current_max);

	fcircuit(f,h,n_ele);
	//fcircuit(Slinks *Link[num_elements] , int num_elements);
	} else{
	printf(" The dimensions of the f and h vector do not match \n");
	}


	return 0;

}
*/
//********************************************************************************************************************
int max_array(int a[], int num_elements) {
	int i, max = 0;
	for (i = 1; i <= num_elements; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return (max);
	}
//********************************************************************************************************************
//void fcircuit(Slink *Link[num_elements] , int num_elements){
void fcircuit(int f[], int h[], int num_elements) {

	// These are just counters for array indexing
	int i, j = 0;

	//Links=(struct Slink*)malloc(num_elements*sizeof(struct Slink));
		 /* Above statement allocates the memory for n structures with pointer ptr pointing to base address */

	/*	for(i=1;i<=num_elements;i++)
			{
			f[i]=(Link[i])->N1;  // Link[i].N1;
			h[i]=(Link[i])->N2;
			}*/
	int node_index=1, edge_index=1;

	int n = 0, fmax = 0, hmax = 0;

	int topofNS ;
	int currentvertex= 0;

	int endflag, mflag =0;

	fmax = max_array(f, num_elements); // max of array f
	hmax = max_array(h, num_elements); //max of array h

	// Max amongst the two arrays
	n = max(fmax,hmax);

	printf(" The max amongst the two arrays is %d \n",n);


	int vertex[n],level[n], prednode[n], prededge[n], node_stack[n];

	int edge[num_elements];

	int difflevel, nodek, edgek,sign,circ_num=0;
	int circ_mat[100][100];
	// This section of the code creates the following vectors
	// vertex, preedge, level and prenode and NS vectors
	for (i = 0; i <= n;i++)
	{
		vertex[i] = 0;
		printf("vertex[%d] = %d \n",i,vertex[i]);
		prededge[i] = 0;
		level[i] = 0;
		prednode[i] = 0;
		node_stack[i] = 0;
	}
	// This section of the code creates the edge vector


	for (i = 0; i <= num_elements; i++)
	{
				edge[i] = 0;
				printf("edge[%d] = %d \n",i,edge[i]);

	}

	int adj_mat[n][num_elements];
	 i = 0;
	 j = 0;

	for (i=0;i <= n; i++) {
		for (j = 0; j <= num_elements; j++) {
			adj_mat[i][j] = 0;
		}
	}
	for (i= 1; i <= num_elements; i++) {
		adj_mat[f[i]][i] = -1;

		adj_mat[h[i]][i] = 1;
	}
	printf("\n Incidence matrix adj_mat = \n");
	for (i=1;i <= n; i++) {
		for (j = 1; j <= num_elements; j++) {

		printf("%d \t",adj_mat[i][j]);
		}
		printf("\n");
		}

	level[f[1]] = 1;
	level[h[1]] = 2;
	node_stack[1] = h[1];
	topofNS = 1;

	prednode[h[1]] = f[1];
	prededge[h[1]] = 1;
	adj_mat[f[1]][1] = 0;
	adj_mat[h[1]][1] = 0;
	currentvertex = f[1];


	endflag = 1;
	int k=1;
	topofNS=1;
int flag=1;
	while ( endflag){

  // Check if there are any unexamined edges incident on current vertex

  printf("\nInside master while loop \n");
    mflag = 1;
    i = 1;
    while ( (i <= num_elements) && (mflag) ){

	printf("Inside second while loop \n");

       if ( adj_mat[currentvertex][i] ){
          edge_index = i ;
          printf("edgeindex%d",edge_index);
          if ( currentvertex == f[edge_index] ){
             node_index = h[edge_index];
			 }
          else{
             node_index = f[edge_index];
			 }

          mflag = 0;
		  }
       else{//printf("chaos");
         ++i;
       }
    }



	// Purposefully added for code testing/debugging. Remove it later
	//mflag =1;
	if ( mflag){
		//printf("%d",topofNS);
// No unexamined edges incident on current vertex.  Remove it from stack

          if ( topofNS == 0 ){
        	//  printf("TOPOFNS=0");
//  Stack is empty.  All F-circuits identified
//  (assuming original graph is connected)

             endflag = 0;
          }
          else  {
        	 //printf("not zero%d",node_stack[topofNS]);
             currentvertex = node_stack[topofNS];
             printf("%dCurrent Vertex",currentvertex);
             topofNS--;
          }
		  }

	 else{

// An unexamined edge adjacent to current vertex and node i has been found

          if (!(level[node_index])){

//  node i is not in tree.  Add edge and node to tree

             topofNS = topofNS + 1;
             node_stack[topofNS] = node_index;
             level[node_index] = level[currentvertex]+1;
             prednode[node_index] = currentvertex;
             prededge[node_index] = edge_index;
			printf("Node index is:%d",level[node_index]);
          }

          else      {
        	  //printf("yahpppppp");
        	  circ_num++;
        	  if(flag==1){


		  for(i=1;i<=num_elements;i++)
		{      circ_mat[num_elements-n+1][i]=0;

		} flag=0;
        	  }
        	  //printf("circ_num:%d\n",circ_num);
        	  //printf("aaa%d%d%d",edge_index,f[edge_index],node_index);

        	  if ( f[edge_index] == node_index ){printf("truth1\n");
        	  printf("circ_mat[%d][%d] is 1:",circ_num,edge_index);
        	  circ_mat[circ_num][edge_index] = 1;}
        	  else{printf("circ_mat[%d][%d] is -1:",circ_num,edge_index);
        	  circ_mat[circ_num][edge_index] = -1;
        	  }
        	  difflevel = level[currentvertex] - level[node_index] + 1;

        	  nodek = currentvertex;
        	  edgek = prededge[currentvertex];
        	  //printf("A%d%d",currentvertex,prededge[currentvertex]);
        	  for(i=1;i<=difflevel;i++)
        	  {
        		  if ( nodek == f[edgek] )// % Determine direction of edge
        		  sign = 1;
        		  else
        		  sign = -1;
        		  printf("Sign is:%d\n",sign);
        		  printf("circ_mat[%d][%d] is %d:\n",circ_num,edgek,sign);
                  circ_mat[circ_num][edgek] = sign;
                  //printf("qq%d",circ_mat[circ_num][edgek]);
                  nodek = prednode[nodek];
                  edgek = prededge[nodek];
                  //printf("%d%d",nodek,edgek);
        	  }

        	  edgek = prededge[node_index];

        	  //printf("qu%d%d",edgek,nodek);
        	  if ( f[edgek] == nodek ){printf("truth2");
        	  printf("circ_mat[%d][%d] is 1:",circ_num,edgek);
        	  circ_mat[circ_num][edgek] = 1;}
        	  else{printf("%d%d",circ_num,edgek);
        	  printf("circ_mat[%d][%d] is -1:",circ_num,edgek);
        	  circ_mat[circ_num][edgek] = -1;
        	  }
          }


	 }
	 adj_mat[f[edge_index]][edge_index] = 0;
	 adj_mat[h[edge_index]][edge_index] = 0;


//    endflag = 0;

	for(i=1;i<=num_elements-n+1;i++)
	{
		for(j=1;j<=num_elements;j++)
			printf("%d\t",circ_mat[i][j]);
			printf("\n");
	}
}
	}
