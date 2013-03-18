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

	/**�δ��б�������poem[k]Ϊ��k�״ʣ�poem[k][i]Ϊ��k�״ʵĵ�i��poem[k][i][j]Ϊ��k�״ʵĵ�i��ĵ�j����*/
	vector<vector<vector<int> > > poemlist;

	/**
     *  �����δ�100�׳�ʼ��Ⱥ
     */
    getpoem(cipai,keywordlist,wordlist,poemlist);

	/**  �Ŵ��㷨����*/
	vector<Chrom> popu;
	vector<Chrom> popuson;
	int best_son_no=0;
	double best_son_res=0.;
	int gen=NOGEN;
	//AfxMessageBox(_T("begin"));
	init_popu(poemlist,popu,keywordlist); /** ��ʼ����Ⱥ */
	for (int i=0;i<gen;i++)                     /** ��ʼ���� */
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