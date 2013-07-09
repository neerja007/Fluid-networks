function [circ_mat] = fcircuit(f,h);
%
%  This function determines the number of fundamental circuit matrix of a
%  given graph.  It is assumed that the given graph is a directed one,
%  fundamental circuits of the underlying undirected graph are determined.
%  The graph has to be input as 2 linear row vectors.
%
%  Inputs
%     f : row vector (1 x e) denoting from nodes of edges
%     h : row vector (1 x e) denoting to nodes of edges
%
%  Output
%     circ_mat : matrix of size (e-n+1)*e.  Entry (i,j) is non-zero if edge j
%                is in circuit i.  Sign is + 1 or -1 depending on orientation
%                of edge vis a vis circuit direction.
%     
%

n = max([f,h]);
e = size(f,2);
vertex = zeros(1,n);    % Initialize all vertices to be absent from ST
edge = zeros(1,e);      % Initialize all edges to be unexamined
level = zeros(1,n);   % Level of each node in ST from root
prednode = zeros(1,n);  % Predecessor nodes of nodes in ST
prededge = zeros(1,n);  % Predecessor edge of nodes in ST
NS = zeros(1,n);        % Stack for nodes
topofNS = 0;
circ_mat = [];
circ_num = 0;           % number of fundamental circuits
%
%  Construct incidence matrix
%  adj_mat(i,j) = -1 if edge j goes from node i to some node
%  adj_mat(i,j) = 1 if edge j goes to node i from some node 
%
adj_mat = zeros(n,e);
for i = 1:e
  adj_mat(f(i),i) = -1;
  display(f(i));
  display(i);
  adj_mat(h(i),i) = 1;

end
disp(adj_mat);
%
%  The first edge (not a self loop) in list is always added to spanning tree 
%  with from node as root
%
level(f(1)) = 1;
level(h(1)) = 2;
NS(1) = h(1);
topofNS = 1;
prednode(h(1)) = f(1);
prededge(h(1)) = 1;
adj_mat(f(1),1) = 0;
adj_mat(h(1),1) = 0;
currentvertex = f(1);
endflag = 1;
while ( endflag ) 
%
%  Check if there are any unexamined edges incident on current vertex
%
    mflag = 1;
    i = 1;
    while ( (i <= e) & (mflag) ),
       if ( adj_mat(currentvertex,i) ),
          edge_index = i;
           display(edge_index);
          if ( currentvertex == f(edge_index) ),
             node_index = h(edge_index);
          else
             node_index = f(edge_index);
          end
          mflag = 0;
       else
         i = i + 1;
       end
    end
   
    if ( mflag ),
%      
%  No unexamined edges incident on current vertex.  Remove it from stack
%      
          if ( topofNS == 0 ),
%       
%  Stack is empty.  All F-circuits identified
%  (assuming original graph is connected)
%       
             endflag = 0;       
          else
             currentvertex = NS(topofNS);
             topofNS = topofNS - 1;
          end
    else
%      
%  An unexamined edge adjacent to current vertex and node i has been found
%
          if ( ~level(node_index) ),
%          
%  node i is not in tree.  Add edge and node to tree
%         
             topofNS = topofNS + 1;
             NS(topofNS) = node_index;
             level(node_index) = level(currentvertex)+1;
             prednode(node_index) = currentvertex;
             prededge(node_index) = edge_index;
          else
%         
%  Output fundamental circuit
%          
             circ_num = circ_num + 1;
             circ_mat = [circ_mat;zeros(1,e)];
             display(circ_num);
             display(edge_index);
             display(f(edge_index));
             display(node_index);
             display(111111111111111111111111111111111111111111);
             if ( f(edge_index) == node_index ),
                circ_mat(circ_num,edge_index) = 1;
                display(22);
                display(circ_num);
                display(edge_index);
                display(22);
             else
                circ_mat(circ_num,edge_index) = -1;
                display(-22);
                display(circ_num);
                display(edge_index);
                display(-22);
             end
             difflevel = level(currentvertex) - level(node_index) + 1;
%
%  Traverse the predecessors starting with currentvertex until
%  predecessor of node_index is obtained
%
             nodek = currentvertex;
             edgek = prededge(currentvertex);  % indices used for traversal
             for j = 1:difflevel,
                if ( nodek == f(edgek) ), % Determine direction of edge
                   sign = 1;
                else
                   sign = -1;
                end
                circ_mat(circ_num,edgek) = sign;
                display(circ_num);
                display(edgek);
                display(sign);
                nodek = prednode(nodek);
                edgek = prededge(nodek);
             end
%
%  nodek should now be the predecessor of node_index.  If not something
%  wrong with coding.  Add edge between node_index and nodek to circuit
%
             edgek = prededge(node_index);
             if ( f(edgek) == nodek ),
                circ_mat(circ_num,edgek) = 1;
                display(circ_mat);
                display(edgek);
                display(11);
             else
                circ_mat(circ_num,edgek) = -1;
                display(circ_num);
                display(edgek);
                display(-11);
             end
          end
%
%  Remove edge from adajency matrix
%
          adj_mat(f(edge_index),edge_index) = 0;
          adj_mat(h(edge_index),edge_index) = 0;
    end
end
