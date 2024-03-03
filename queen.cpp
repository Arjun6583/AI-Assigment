#include<iostream>
#include<set>
#include<vector>

using namespace std;

class Queen
{
	public: 

		Queen()
		{
			
		}

		void init()
		{
			vector<string>cur(n, string(n, '.'));

			dfs(0, cur);

			for(int i = 0; i < res.size(); ++i)
			{
				for(int j = 0; j < res[i].size(); ++j)
				{
					for(int k = 0; k < res[i][j].size(); ++k)
					{
						cout<<res[i][j][k]<<"  ";
					}
					cout<<"\n";
				}
				cout<<"\n\n";
			}
		}
	private: 
		set<int>coll;
		set<int>negD;
		set<int>posD;
		vector<vector<string>> res;
		int n = 8;
		int new_col, new_row; 

		void dfs(int row, vector<string>&cur)
		{
			if(row == new_row)
			{
				dfs(row + 1, cur);
				return;
			}
			if(row == n)
			{
				res.push_back(cur);
				return;
			}

			for(int col = 0; col < n; ++col)
			{
				if(coll.count(col) || negD.count(row - col) || posD.count(row + col))
					continue;
				cur[row][col] = 'Q';
				coll.insert(col);
				negD.insert(row - col);
				posD.insert(row + col);

				dfs(row + 1, cur);

				cur[row][col] = '.';
				coll.erase(col);
				negD.erase(row - col);
				posD.erase(row + col);
			}
		}

};
int main()
{
	Queen ob;
	ob.init();
}