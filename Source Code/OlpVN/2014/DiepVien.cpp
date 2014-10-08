#include<cstdio>
#include<climits>

int m, n;
int x1, y1, x2, y2;
bool a[100][100];
bool visited[10000][10000];
int min_path[10000][2];
int min_path_length=INT_MAX;

void Run(int path[][2], int path_length, bool dir, bool flag)
{
	int first, last;
	
	if(path[path_length-1][0]==x2 && path[path_length-1][1] == y2 && path_length < min_path_length)
	{
		// Update min_path_length
		min_path_length = path_length;
		// Update min_path;
		for(int i = 0; i < path_length; ++i)
		{
			min_path[i][0] = path[i][0];
			min_path[i][1] = path[i][1];
		}	
	}
	else
	{
		// Try visiting
		first = path[path_length-1][0]*n + path[path_length-1][1];
		
		if(dir)
		{
			// Vua di theo huong nam ngang
			if(!flag)
			{
				// flag == false khong phai la quay lai huong cu => thu quay lai huong cu
				path[path_length][0] = path[path_length-2][0];
				path[path_length][1] = path[path_length-2][1];
			
				last = path[path_length][0]*n + path[path_length][1];
				
				visited[first][last] = true;
				Run(path, path_length+1, dir, true);
				visited[first][last] = false;
			}
			
			// Di doc len
			if (path[path_length-1][0]-1 > 0 && !a[path[path_length-1][0]-1][path[path_length-1][1]])
			{
				last = first-n;
				
				if(!visited[first][last])
				{
					path[path_length][0] = path[path_length-1][0] - 1;
					path[path_length][1] = path[path_length-1][1];
					
					visited[first][last] = true;
					Run(path, path_length+1, !dir, false);
					visited[first][last] = false;
				}
			}
			// Di doc xuong
			if (path[path_length-1][0]+1 < n && !a[path[path_length-1][0]+1][path[path_length-1][1]])
			{
				last = first+n;
				
				if(!visited[first][last])
				{
					path[path_length][0] = path[path_length-1][0] + 1;
					path[path_length][1] = path[path_length-1][1];
					
					visited[first][last] = true;
					Run(path, path_length+1, !dir, false);
					visited[first][last] = false;
				}
			}
		}
		else
		{
			// Vua di theo huong nam doc va khong phai la quay lai huong cu
			// Vua di theo huong nam doc
			if(!flag)
			{
				// flag == false khong phai la quay lai huong cu => thu quay lai huong cu
				path[path_length][0] = path[path_length-2][0];
				path[path_length][1] = path[path_length-2][1];
				
				last = path[path_length][0]*n + path[path_length][1];
				
				visited[first][last] = true;
				Run(path, path_length+1, dir, true);
				visited[first][last] = false;
			}
			// Di ngang sang trai
			if (path[path_length-1][1]-1 > 0 && !a[path[path_length-1][0]][path[path_length-1][1]-1])
			{
				last = first-1;
				
				if(!visited[first][last])
				{
					path[path_length][0] = path[path_length-1][0];
					path[path_length][1] = path[path_length-1][1]-1;
					
					visited[first][last] = true;
					Run(path, path_length+1, !dir, false);
					visited[first][last] = false;
				}
			}
			// Di ngang sang phai
			if (path[path_length-1][1]+1 < m && !a[path[path_length-1][0]][path[path_length-1][1]+1])
			{
				last = first+1;
				
				if(!visited[first][last])
				{
					path[path_length][0] = path[path_length-1][0];
					path[path_length][1] = path[path_length-1][1]+1;
					
					visited[first][last] = true;
					Run(path, path_length+1, !dir, false);
					visited[first][last] = false;
				}
			}
		}
	}
}
int main()
{
	int x, y;
	scanf("%d%d", &m, &n);
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	
	while(scanf("%d%d",&x, &y) > 0) a[x][y] = true;
	int path[10000][2];
	path[0][0] = x1;
	path[0][1] = y1;
	
	Run(path, 1, true, true);
	Run(path, 1, false, true);
	
	printf("%d", min_path_length);
	
	/*for(int i = 0; i < min_path_length; ++i)
	{
		printf("\n%d %d", path[i][0], path[i][1]);
	}*/
}
