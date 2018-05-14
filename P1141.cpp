#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

struct node{
	int x,y;
}maptmp[1001];

int draw(int x,int y) //To-Do

int addmaptmp(int x,int y)
{
	count++;
	maptmp[count].x=x;
	maptmp[count].y=y;
}

int structfirstrunclear()
{
	for(int i=0;i<1001;i++)
	{
		maptmp.x=-1;
		maptmp.y=-1;
	}
}

int structclear(int x)
{
	for(int i=0;i<x;i++)
	{
		maptmp.x=-1;
		maptmp.y=-1;
	}
}

int map[1001][1001];
int mapans[1001][1001]; 
int n,m;
int count=0;

bool move(int xa,int ya,int xb,int yb)
{
	if(map[xa][ya]+map[xb][yb]==1) return true;
	else return false; 
}

int dfs(int x,int y)
{
	if(mapans!=-1) return;
	if(x>=n&&x<0&&y>=m&&y<0) 
	{
		return;
	}
	count++;
	if(move(x,y,x+1,y)) 
	{
		dfs(x+1,y);
	}
	if(move(x,y,x,y+1)) 
	{
		dfs(x,y+1);
	}
	if(move(x,y,x-1,y)) 
	{
		dfs(x-1,y);
	}
	if(move(x,y,x,y-1))
	{
		dfs(x,y-1);
	} 
}

int main()
{

	memset(mapans,-1,sizeof(mapans));
	structfirstrunclear();

	 
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&map[i][j]);
		}
	 } 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			count=0;
			dfs(i,j);
		}
	}
	return 0;
 } 
