#include<cstdio>
#include<queue>
#include<map>
#define N 5001
using namespace std;

class point
{
public:
	int x;
	int y;
	// Phuc vu cho map so sanh 2 toa do
	bool operator <(const point& rhs) const
    {
        return (x != rhs.x || y != rhs.y);
    }
};

int main()
{
	int test;
	int i;
	int x1,y1,x2,y2;
	int V,H,K;
	char d[N];
	int VG[N],HG[N];
	
	scanf("%d",&test);
	
	while(test--)
	{
		scanf("%d%d%d",&V,&H,&K);
		VG[0]=0;
		HG[0]=0;
		//Doc va tinh cac chi so cot: 1 1 2 1 1 => 0 1 2 4 5 6 
		for(i=1;i<V;i++)
		{
			scanf("%d",&VG[i]);
			VG[i]+=VG[i-1];
		}
		//Doc va tinh cac chi so hang: 1 1 2 1 1 => 0 1 2 4 5 6 
		for(i=1;i<H;i++)
		{
			scanf("%d",&HG[i]);
			HG[i]+=HG[i-1];
		}
		// VE anh xa toi cac chi so cot, tang hoac giam 1 cot tuy vao huong
		// HE anh xa toi cac chi so hang, tang hoac giam 1 hang tuy vao huong
		map<int,int> VE,HE;
		map<int,int>::iterator it;
		// Doc huong di tuong ung voi tung cot, toa do (0,0) o duoi cung ben trai
		// Huong Bac (N) di len tren => tren cot dang xet co the di +1 len tren
		// Huong Nam (S) di xuong duoi => tren cot dang xet co the di -1 xuong duoi
		// {0 1 2 4 5 6} + "NNNSSS" => VE[0]=1, VE[1]=1, VE[2]=1,VE[3]=-1,...
		scanf("%s",&d);

		for(i=0;i<V;i++)
		{
			if(d[i]=='N') VE[VG[i]]=1;
			else VE[VG[i]]=-1;
		}
		// Doc huong di tuong ung voi tung hang, toa do (0,0) o duoi cung ben trai
		// Huong Tay (W) di sang trai => tren hang dang xet co the di -1 sang trai
		// Huong Dong (E) di sang phai => tren hang dang xet co the di +1 sang phai
		// {0 1 2 4 5 6} + "WWWEEE" => HE[0]=-1, HE[1]=-1, HE[2]=-1,HE[3]=1,...
		scanf("%s",&d);
		
		for(i=0;i<H;i++)
		{
			if(d[i]=='W') HE[HG[i]]=-1;
			else HE[HG[i]]=1;
		}
		// t la diem 
		pair<int, point> t;
		// p la diem 
		point p,p1;
		
		while(K--)
		{
			// Doc toa do bat dau (x1, y1) va toa do dich (x2, y2)
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			// Truong hop toa do dau va dich trung nhau in ra 0
			if(x1==x2&&y1==y2)
			{
				printf("0");
				
				if(K>0) printf("\n");
				continue;
			}
			// Map danh dau toa do da duoc ghe tham hay chua
			map<point,bool> Visited;
			map<point,bool>::iterator itv;
			// Hang doi uu tien sap xep cac phan tu trong hang doi theo nguyen tac:
			// mac dinh khong tang theo gia tri dau tien, o day la gia tri kieu (int)
			// trong pair<int, point>, point la diem cuoi cung vua ghe tham 
			// tren quang duong ngan nhat.
			priority_queue< pair<int, point> > q;
			// Dua toa do bat dau (x1,y1) vao hang doi, do dai duong di la 0
			p.x=x1;
			p.y=y1;
			// Da ghe tham
			Visited[p]=true;
			q.push(make_pair(0, p));
			
			while(!q.empty())
			{
				// Lay phan tu dau hang doi
				t=q.top();
				q.pop();
				// Lay toa do
				p=t.second;
				
				// Tim xem tai hang x co the sang trai, sang phai, hay khong duoc
				it=HE.find(p.x);
				// Neu tim thay chi so hang trong map HE nghia la di duoc voi
				// gia tri gia tang la gia tri anh xa tuong ung (second)
				if(it!=HE.end())
				{
					// Lay toa do diem ghe tham tiep theo
					p1.x = p.x;
					p1.y = p.y + it->second;
					// La toa do dich den => in ket qua va dung vong lap
					if(p1.x==x2&&p1.y==y2)
					{
						printf("%d",1-t.first);
						break;
					}
					// toa do nam trong ban do
					if(p1.x>=0&&p1.y>=0&&p1.x<=HG[H-1]&&p1.y<=VG[V-1])
					{
						// tim xem toa do da duoc ghe tham chua
						itv=Visited.find(p1);
						// toa do chua duoc ghe tham
						if(itv==Visited.end()) 
						{
							// tham 
							Visited[p1]=true;
							// Ta can lay gia gia tri nho nhat o dau hang doi sau moi lan lap
							// trong khi hang doi lai uu tien sap xep khong tang nen ta phai
							// truyen vao gia tri am bang cach -1 moi lan day vao
							q.push(make_pair(t.first-1, p1));
						}
					}
				}
				// Tim xem tai cot y co the len tren, xuong duoi, hay khong duoc
				// Tuong tu voi hang
				it=VE.find(p.y);
				
				if(it!=VE.end())
				{
					p1.x=p.x + it->second;
					p1.y=p.y;

					if(p1.x==x2&&p1.y==y2)
					{
						printf("%d",1-t.first);
						break;
					}
					
					if(p1.x>=0&&p1.y>=0&&p1.x<=HG[H-1]&&p1.y<=VG[V-1])
					{
						itv=Visited.find(p1);
						
						if(itv==Visited.end()) 
						{
							Visited[p1]=true;
							q.push(make_pair(t.first-1,p1));
						}
					}
				}
			}
			
			if(p.x!=x2&&p.y!=y2) printf("-1");
			
			if(K>0) printf("\n");
		}
	}

	return 0;
}
