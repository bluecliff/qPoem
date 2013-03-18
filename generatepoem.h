#ifndef GENERATEPOEM_H_
#define GENERATEPOEM_H_
#include <vector>
//#include "getpoem.h"
#include "stdafx.h"
#include "ga.h"

bool generate_poem(int cipai,int keyword,vector<vector<int> >& poem)
{
	vector<int> wordlist;
	vector<int> keywordlist;

	keywordlist.push_back(keyword);

	/**宋词列表，共三级poem[k]为第k首词，poem[k][i]为第k首词的第i句poem[k][i][j]为第k首词的第i句的第j个词*/
	vector<vector<vector<int> > > poemlist;

	/**
     *  生成宋词100首初始种群
     */
    getpoem(cipai,keywordlist,wordlist,poemlist);

	/**  遗传算法处理*/
	vector<Chrom> popu;
	vector<Chrom> popuson;
	int best_son_no=0;
	double best_son_res=0.;
	int gen=NOGEN;
	//AfxMessageBox(_T("begin"));
	init_popu(poemlist,popu,keywordlist); /** 初始化种群 */
	for (int i=0;i<gen;i++)                     /** 开始迭代 */
	{
		best_son_no=ga_pro(popu,popuson,i,keywordlist,wordlist,cipai);
		popu.assign(popuson.begin(),popuson.end());
	}
	//poem=poemlist[0];
	//AfxMessageBox(_T("ok"));
	poem=popu[best_son_no].indiv;
	return true;
}


#endif