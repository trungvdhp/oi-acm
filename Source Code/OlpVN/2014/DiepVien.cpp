#include <cstdio>
#include <climits>
#define MAX_LENGTH 10000
int m, n;
int x1, y1, x2, y2;
bool a[100][100];
bool visited[10000][10000];
char min_path[MAX_LENGTH][2];
int min_path_length=MAX_LENGTH;

// path: duong di hien tai
// length: do dai duong di hien tai
// prev_direction (previous direction): Huong di truoc do la ngang hay doc?
// true la huong ngang, false la huong doc
// returned: xac dinh xem truoc do co phai la quay lai huong cu khong?
// true  : huong di truoc do la huong cu 
// false : huong di truoc do khong phai la huong cu
void Run(char path[][2], int length, bool prev_direction, bool returned)
{
	int start, dest;
	// Do dai duong di hien tai >= do dai duong di ngan nhat hien tai
	// => khong can thu di tiep
	if(length >= min_path_length) return;
	
	// Da di toi diem hen va do dai duong di < do dai duong di ngan nhat hien tai
	if(path[length-1][0] == x2 && path[length-1][1] == y2 && length < min_path_length)
	{
		// Cap nhat do dai duong di ngan nhat
		min_path_length = length;
		//printf("\n%d\n", min_path_length-1);
		// Cap nhat toa do cac diem tren duong di ngan nhat
		for(int i = 0; i < length; ++i)
		{
			//printf("(%d %d) ", path[i][0], path[i][1]);
			min_path[i][0] = path[i][0];
			min_path[i][1] = path[i][1];
		}	
	}
	else
	{
		start = path[length-1][0]*m + path[length-1][1];
		
		if(prev_direction)
		{
			// Vua di theo huong ngang
			// Di doc len
			// Neu khong di ra khoi thanh pho va khong qua tram kiem soat
			if (path[length-1][0]-1 >= 0 && !a[path[length-1][0]-1][path[length-1][1]])
			{
				
				dest = start-m;
				// Neu chua di tu pho start toi pho dest thi thu di
				if(!visited[start][dest])
				{
					path[length][0] = path[length-1][0] - 1;
					path[length][1] = path[length-1][1];
					
					visited[start][dest] = true;
					Run(path, length+1, !prev_direction, false);
					visited[start][dest] = false;
				}
			}
			// Di doc xuong
			if (path[length-1][0]+1 < n && !a[path[length-1][0]+1][path[length-1][1]])
			{
				
				dest = start+m;
				
				if(!visited[start][dest])
				{
					path[length][0] = path[length-1][0] + 1;
					path[length][1] = path[length-1][1];
					
					visited[start][dest] = true;
					Run(path, length+1, !prev_direction, false);
					visited[start][dest] = false;
				}
			}
		}
		else
		{
			// Vua di theo huong doc
			// Di ngang sang trai
			if (path[length-1][1]-1 >= 0 && !a[path[length-1][0]][path[length-1][1]-1])
			{
				dest = start-1;
				
				if(!visited[start][dest])
				{
					path[length][0] = path[length-1][0];
					path[length][1] = path[length-1][1]-1;
					
					visited[start][dest] = true;
					Run(path, length+1, !prev_direction, false);
					visited[start][dest] = false;
				}
			}
			// Di ngang sang phai
			if (path[length-1][1]+1 < m && !a[path[length-1][0]][path[length-1][1]+1])
			{
				
				dest = start+1;
				
				if(!visited[start][dest])
				{
					path[length][0] = path[length-1][0];
					path[length][1] = path[length-1][1]+1;
					
					visited[start][dest] = true;
					Run(path, length+1, !prev_direction, false);
					visited[start][dest] = false;
				}
			}
		}
		
		// Huong di truoc do khong phai la huong cu
		// quay lai huong cu
		if(!returned)
		{
			path[length][0] = path[length-2][0];
			path[length][1] = path[length-2][1];
		
			dest = path[length][0]*m + path[length][1];
			
			visited[start][dest] = true;
			Run(path, length+1, prev_direction, true);
			visited[start][dest] = false;
		}
	}
}
int main()
{
	int x, y;
	scanf("%d%d", &m, &n);
	m++;
	n++;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	
	while(scanf("%d%d",&x, &y) > 0) a[x][y] = true;
	
	if(a[x2][y2]) 
	{
		printf("NO");
		return 0;
	}
	
	char path[MAX_LENGTH][2];
	path[0][0] = x1;
	path[0][1] = y1;
	
	Run(path, 1, true, true);
	Run(path, 1, false, true);
	
	if(min_path_length == MAX_LENGTH) printf("NO");
	else
	{
		printf("%d", min_path_length-1);
		
		for(int i = 0; i < min_path_length; ++i)
		{
			printf("\n%d %d", min_path[i][0], min_path[i][1]);
		}
	}
}
