#include<stdio.h>
#include<vars.h>

//********************************************************************************************************************

int main() {
	//int Nlinks=2;
	//printf("%d",Nlinks);


	int current_max = 0;
	int f[Nlinks];
	int h[Nlinks];
	int x[1000];// dynamic array allocation yet to be implemented
	int y[1000];//dynamic array alloc yet to be implemented
	int i;
	/*f[0] = 0; // one indexing
	f[1] = 1;
	f[2] = 2;
	f[3] = 3;
	f[4] = 4;
	f[5] = 5;
*/
	  //printf("Enter n: ");
	  //scanf("%d",&n);
	  Links=(struct Slink*)malloc(Nlinks*sizeof(struct Slink));
	 /* Above statement allocates the memory for n structures with pointer ptr pointing to base address */
	  Nodes=(struct Snode*)malloc(Nnodes*sizeof(struct Snode));



	/*for(i=1;i<=Nlinks;i++)
		{
		f[i]=(Link[i])->N1;  // Link[i].N1;
		h[i]=(Link[i])->N2;
		}
	int k=1;
for(i=1;i<=Nnode;i++)
{
if(((Node[i].Pdemand)&&(Node[i].Psource))==NULL){
	x[i]=f[i];
	y[i]=h[i];
k++;
}}
for(i=1;i<=Nnode;i++){
if((Node[i].Pdemand)==NULL){
	k++;
	x[k]=Node[i];
	y[k]=i;

}
else if((Node[i].Psource)==NULL){
	k++;
	x[k]=i;
	y[k]=Node[i];
}
}*/
	h[0] = 0; //one indexing
	//h[1] = 2;
	//h[2] = 3;
	//h[3] = 4;
	//h[4] = 5;
	//h[5] = 1;
	//int f_size = sizeof(f)/sizeof(f[0]);
	//int h_size = sizeof(h)/sizeof(h[0]);
	int f_size=Nlinks;
	int h_size=Nlinks;
	int k=0;
	//printf(" The size of the f vector is %d \n",f_size);
	//printf(" The size of the h vector is %d \n",h_size);
	int x_size=Nlinks+k;
	int y_size=Nlinks+k;
	if(x_size == y_size){

	// The number of elements in the vectors
	int n_ele = x_size-1;


	current_max = max_array(x,n_ele);
	printf("The max of x vector is %d \n", current_max);

	//fcircuit(f,h,n_ele);
	fcircuit(Slink *Link,Snode *Node,int Nlinks,int Nnodes);
	} else{
	printf("Error: The dimensions of the x and y vector do not match \n");
	}


	return 0;

}

//********************************************************************************************************************
int max_array(int a[], int Nlinks) {
	int i, max = 0;
	for (i = 1; i <= Nlinks; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return (max);
	}
//********************************************************************************************************************
void fcircuit(Slink *Link , Snode *Node, int Nlinks , int Nnodes){
//void fcircuit(int f[], int h[], int Nlinks) {

	// These are just counters for array indexing
	int i, j = 0;
	int f[Nlinks];
		int h[Nlinks];
		int x[1000];// dynamic array allocation yet to be implemented
		int y[1000];//dynamic array alloc yet to be implemented
		int i;
	//int f[Nlinks];//int f[6];
	//int h[Nlinks];//int h[6];
	//Links=(struct Slink*)malloc(Nlinks*sizeof(struct Slink));
		 /* Above statement allocates the memory for n structures with pointer ptr pointing to base address */

	/*	for(i=1;i<=Nlinks;i++)
			{
			f[i]=(Link[i])->N1;  // Link[i].N1;
			h[i]=(Link[i])->N2;
			}*/
	for(i=1;i<=Nlinks;i++)
			{
			f[i]=(Link[i])->N1;  // Link[i].N1;
			h[i]=(Link[i])->N2;
			}
		int k=1;
	for(i=1;i<=Nnode;i++)
	{
	if(((Node[i].Pdemand)&&(Node[i].Psource))==NULL){
		x[i]=f[i];
		y[i]=h[i];
	k++;
	}}
	for(i=1;i<=Nnode;i++){
	if((Node[i].Pdemand)==NULL){
		k++;
		x[k]=Node[i];
		y[k]=i;

	}
	else if((Node[i].Psource)==NULL){
		k++;
		x[k]=i;
		y[k]=Node[i];
	}
	}
	int x_size=Nlinks+k;
	int y_size=Nlinks+k;
	int node_index=1, edge_index=1;

	int n = 0, fmax = 0, hmax = 0;

	int topofNS ;
	int currentvertex= 0;

	int endflag, mflag =0;
	int xmax,ymax;
	xmax = max_array(x, Nlinks+k); // max of array f
	ymax = max_array(y, Nlinks+k); //max of array h

	// Max amongst the two arrays
	n = max(xmax,ymax);

	printf(" The max amongst the two arrays is %d \n",n);


	int vertex[n],level[n], prednode[n], prededge[n], node_stack[n];

	int edge[Nlinks+k];

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


	for (i = 0; i <= Nlinks+k; i++)
	{
				edge[i] = 0;
				printf("edge[%d] = %d \n",i,edge[i]);

	}

	int adj_mat[n][Nlinks+k];
	 i = 0;
	 j = 0;

	for (i=0;i <= n; i++) {
		for (j = 0; j <= Nlinks+k; j++) {
			adj_mat[i][j] = 0;
		}
	}
	for (i= 1; i <= Nlinks+k; i++) {
		adj_mat[f[i]][i] = -1;

		adj_mat[h[i]][i] = 1;
	}
	printf("\n Incidence matrix adj_mat = \n");
	for (i=1;i <= n; i++) {
		for (j = 1; j <= Nlinks+k; j++) {

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

	while ( endflag!=0 ){


  // Check if there are any unexamined edges incident on current vertex

  printf("\nInside master while loop \n");
    mflag = 1;
    i = 1;
    while ( (i <= Nlinks+k) && (mflag) ){

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
	if ( mflag>0 ){
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
		  for(i=1;i<=Nlinks+k;i++)
		{      circ_mat[Nlinks+k-n][i]=0;

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

	for(i=1;i<=Nlinks+k-n+1;i++)
	{
		for(j=1;j<=Nlinks+k;j++)
			printf("%d\t",circ_mat[i][j]);
	}
}

}
