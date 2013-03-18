#ifndef GA_H_
#define GA_H_

#include "getpoem.h"
#include <limits.h>
/**
 *     @file  ga.h
 *     @brief  GA 算法处理流程 
 *     @author  NanKor (NK), mkzmkzmkz1988@gmail.com
 *     @date  2012年11月05日 18时10分26秒
 *    Compiler  gcc/g++
 *     Company  XiDian Univ
 *   Copyright  Copyright (c) 2012, NanKor
 */

using namespace std;

#define POPSIZE     200                            /**  population size 种群大小*/ 
#define NOGEN       100                             /**  遗传代数*/ 
#define PXOVER      0.8                            /**  probability of crossover 杂交概率*/ 
#define PMUTATION   0.9                            /**  probability of mutation 变异概率 0.7*/ 
#define NOMUTATION  1                              /**  变异操作次数 1 */
#define NOCROSS     50                             /** 交叉次数 */
#define PFATHEROK   0.3                            /**  父代接受概率 0.3*/
#define ASPECT      3                              /**  适应度指标数量  */
#define DEBUGMODE   0                              /** DEBUG模式 */
#define COUNTTIME   50                             /** 变异时寻找优于原来单词的步数  */
#define RE_TIME     10                             /** 相关度的权值 */
#define EM_TIME     1                              /** 变异时情感方差的权值  */
#define PCLEVER     0.8                            /**  由于词数少的句子情感得分方差大，极大可能是本首次内适应度最小的句子，如若交叉变异一直选择此句，改变的词数较少，故以该概率接受选择交叉其他句子进行交叉变异，以增长交叉的长度与变异的基因序列长度  */
#define SHAMETIME   4
/**
 * @class sen_no_res
 * @brief 获取一首词中适应度最小的句子编号与适应度
 */
struct sen_no_res{
    int sen_no;                                 /** 该句从0开始计数 */
    double sen_res;                             /** 该句ASPECT方面的适应度之和 */
};


/**
 * @class chromosome
 * @brief 一首词做为染色体个体，包含词内容，总适应度，最小适应度句子
 */
struct chromosome {
    vector<vector<int> > indiv;                 /** 一首词 */
    double  indiv_res[ASPECT];                  /** 该首词整体的适应度 */
    struct sen_no_res  minres_sen;              /**  该首词中最小适应度的句子号与其平均适应度 */

    /** 
     * @brief operator=  重载=，做为struct赋值 
     * @param chromosome src 
     * @return chromosome
     * 
     */
    chromosome& operator= (chromosome& src)     
    {
        indiv.assign(src.indiv.begin(),src.indiv.end());
        for ( int i = 0; i < ASPECT ; ++i )
        {
            indiv_res[i]=src.indiv_res[i];
        }
        minres_sen.sen_no=src.minres_sen.sen_no;
        minres_sen.sen_res=src.minres_sen.sen_res;
        return *this;
    }
};				                                    

typedef struct chromosome  Chrom;

/** 
 * @brief greatbf_af  比较两个个体的适应度 before>after
 * @param  const chromosome & before,const chromosome & after
 * @return true:before>after false:before<after
 * 
 */
bool greatbf_af(const chromosome & before,const chromosome & after);


/** 
 * @brief cre_random 产生[start,end]间的随机数
 * @param double start, double end  
 * @return double 随机数
 * 
 */
double cre_random ( double start,double end );


/** 
 * @brief disp_poem 显示一首词内容
 * @param  vector<vector<int > > onepoem
 * @return NULL
 * 
 */

void disp_poem ( vector<vector<int > > onepoem );

/** 
 * @brief disp_chrom 显示染色体内容 
 * @param  Chrom onechrom 
 * @return NULL
 * 
 */
void disp_chrom ( Chrom  onechrom);

/** 
 * @brief comp_poem_re 
 * @param vector<int> keyword, Chrom& onechrom
 * @return double 含有惩罚的整首词总体的相关度得分×10
 * 
 */
double comp_poem_re (vector<int> keyword, Chrom& onechrom);


/** 
 * @brief comp_res 计算某条染色体的适应度与最小适应度的句子与编号
 * @param vector<int> keyword, Chrom& onechrom
 * @return int 1 成功 int -1 失败
 * 
 */
int comp_res(vector<int> keyword, Chrom& onechrom);


/** 
 * @brief init_chrom 初始化一条染色体 
 * @param vector<vector<int> > poemindiv, Chrom &  onechrom, vector<int> keyword 
 * @return int 1 成功 int -1 失败
 * 
 */
int init_chrom(vector<vector<int> > poemindiv, Chrom &  onechrom, vector<int> keyword); 


/** 
 * @brief crossover_chrom 两首词中最小适应度的句子进行交叉 
 * @param Chrom & firchrom, Chrom & secchrom,vector<int> keyword待交叉的父代
 * @return int  1 成功 int -1 失败
 * 
 */
void crossover_chrom (Chrom & firchrom, Chrom & secchrom,vector<int> keyword);


/** 
 * @brief search_best 选取种群中最优的个体 
 * @param  vector<Chrom > & popu
 * @return int 返回最优个体的编号 
 * 
 */
int search_best(vector<Chrom > & popu);


/** 
 * @brief init_popu 初始化种群 
 * @param vector<vector<vector<int > > >& oripopu,vector<Chrom>& orifather, vector<int> keyword 
 * @return null 
 * 
 */
void init_popu(vector<vector<vector<int > > >& oripopu,vector<Chrom>& orifather, vector<int> keyword) ;


/** 
 * @brief chose_inher 选择遗传 
 * @param vector<Chrom>& father,vector<Chrom>& son
 * @return NULL
 * 
 */
void chose_inher(vector<Chrom>& father,vector<Chrom>& son);

/** 
 * @brief change_dfa_one 
 * @param Chrom onechrom,vector<Chrom> popu,int muta_sen_no,vector<int> keyword
 * @return int 1 成功 int -1 失败
 * 
 */
int  change_dfa_one(Chrom onechrom,vector<Chrom> popu,int muta_sen_no,vector<int> keyword);


/** 
 * @brief get_pz_fr_pat 从一句pattern中获取第wordth个单词的平仄字符串,wordth 从0计数 
 * @param string pattern,int wordth,string & wordpz
 * @return
 * 
 */
int get_pz_fr_pat(string pattern,int wordth,string & wordpz); 


/** 
 * @brief muat_sen 变异onechrom[muta_sen_no]中的某个单词 
 * @param Chrom onechrom,int muta_sen_no,vector<int> keyword,vector<int> wordlist,int cipai
 * @return int 1 正变异即变异后更优 int 0 变异之后适应度没变化 int -1 负变异
 * 
 */
int muta_sen(Chrom onechrom,int muta_sen_no,vector<int> keyword,vector<int> wordlist,int cipai);



/** 
 * @brief muat 
 * @param Chrom & onechrom,vector<Chrom> popu,vector<int > keyword,vector<int > & wordlist,int cipai
 * @return 0 没有变异 1 正变异或者dfa变异通过 -1负变异或者DFA变异没有通过
 * 
 */
int  muta(Chrom & onechrom,vector<Chrom> popu,vector<int > keyword,vector<int > & wordlist,int cipai);


/** 
 * @brief ga_pro 遗传算法流程 
 * @param vector<Chrom>& father,vector<Chrom>& son, int gen,vector<int> keyword,vector<int> wordlist 
 * @return 最优子代的编号
 * 
 */
int ga_pro(vector<Chrom>& father,vector<Chrom>& son, int gen,vector<int> keyword,vector<int > wordlist,int cipai);

bool greatbf_af(const chromosome & before,const chromosome & after)
{
    double this_sum=0;
    double src_sum=0;
    for ( int j = 0; j < ASPECT; ++j )
    {
        this_sum+=before.indiv_res[j];
        src_sum+=after.indiv_res[j];
    }
    return this_sum>src_sum;
}

double cre_random ( double start,double end )
{
    return start+(end-start)*rand()/(RAND_MAX+1.0);
}		


void disp_poem ( vector<vector<int > > onepoem )
{
    for ( int i = 0; i < onepoem.size(); ++i )
    {
        for ( int j = 0; j < onepoem[i].size(); ++j )
        {
            cout<< onepoem[i][j] << " ";
        }
        cout <<endl;
    }
}		


void disp_chrom(Chrom onechrom)
{
    disp_poem(onechrom.indiv);
    for ( int i = 0; i < ASPECT; i++ )
    {
        cout<<"RES "<< i <<" of poem :"<<onechrom.indiv_res[i]<< endl;
    }
    cout<<"Min_res_sen_no:"<<onechrom.minres_sen.sen_no<<endl;
    cout<<"Min_res_sen_res:"<<onechrom.minres_sen.sen_res<<endl;
}


double comp_poem_re (vector<int> keyword, Chrom& onechrom)
{
    ifstream finrev;
    finrev.open("reva.data",ios::in|ios::binary); /**  wordslib.data 主要是单词列表  */
    double poem_re=0.;
    int j=0;
    for ( j = 0; j < onechrom.indiv.size(); j++ )
    {
        poem_re += re_evaluate(onechrom.indiv[j],keyword,finrev); /**  本句词的总体相关度评价 */
    }

    /**
     *  对于某首词中因为使用多个重复的词，进行惩罚，以避免因使用重复词造成的
     *  相关度与情感得分的增加
     */
    vector<int > poem_sort;
    int k=0;
    for(k=0;k<onechrom.indiv.size();k++)
    {
        for (j=0;j<onechrom.indiv[k].size();j++)
        {
            poem_sort.push_back(onechrom.indiv[k][j]);
        }
    }

    sort(poem_sort.begin(),poem_sort.end(),greater<int>());
    int count_re=0;                             /** 计算一首词内所有重复词重复的词数 */
    for(int i=1;i<poem_sort.size();i++)
    {
        if(poem_sort[i]==poem_sort[i-1])
            count_re++;
    }
    double aver_re=poem_re/poem_sort.size();
    poem_re=aver_re*(poem_sort.size()-count_re*SHAMETIME)*RE_TIME; /** SHAMETIME倍惩罚重复词 */
    finrev.close();
    return poem_re;
}


int comp_res(vector<int> keyword, Chrom& onechrom)
{
    ifstream finrev;
    finrev.open("reva.data",ios::in|ios::binary); /**  reve.data主要是两个单词之间的相关度矩阵 */
    ifstream finword;
    finword.open("wordslib.data",ios::in|ios::binary); /**   wordslib.data 主要是单词列表  */
    double res_sen_j=0.,sen_syta=0.,sen_re=0.,sen_emo=0.; 
    /** res_sen_j记录当前句子的得分 
     * sen_syta记录当前句子的语法评价的函数结果 
     * sen_emo记录当前句子的情感评价函数的结果
     * sen_re 记录当前句子的与主题相关度的函数评价结果
     */

    int j=0;
    for ( j=0;j < onechrom.indiv.size(); j++ )   /** 遍历该首词内的每句 */
    {
        res_sen_j=0.;
        for ( int i = 0; i< ASPECT; i++ )       /** 计算每句在ASPECT个方面的评价结果 并求得该首词总的适应度 */
        {	
            if ( j==0 )
            {
                onechrom.indiv_res[i]=0.;
                onechrom.minres_sen.sen_no=0;
                onechrom.minres_sen.sen_res=0.;
            }
            switch (i)
            {
                case 0:
                    sen_syta = sytax_evaluate(onechrom.indiv[j],finword); /** 获取本句的语法正确性 即验证DFA 通过为1 否则为0 */
                    onechrom.indiv_res[i] +=sen_syta;
                    res_sen_j +=sen_syta;
                    break;
                case 1:
                    sen_re =  re_evaluate(onechrom.indiv[j],keyword,finrev); /**  本句词的总体相关度评价 */
                    res_sen_j += (sen_re/onechrom.indiv[j].size()); /** 由于每句的单词数目不一样，必须除以该句词数计算平均相关度 */
                    break;
                case 2:
                    sen_emo = emotion_evaluate(onechrom.indiv[j],finword); /**  本句词的情感统一性 */
                    onechrom.indiv_res[i] += sen_emo;
                    res_sen_j +=sen_emo; 
                    break;
                default:
                    cout<<"error ASPECT"<<endl;
                    finword.close();
                    finrev.close();
                    return -1;
            }
        }
        /** 取得该首词内适应度最小的句子编号与相应句子的适应度 */
        if ( j==0 )
        {
            onechrom.minres_sen.sen_res=res_sen_j;
            onechrom.minres_sen.sen_no=j;
        }
        else{
            if (onechrom.minres_sen.sen_res >= res_sen_j)
            {
                onechrom.minres_sen.sen_res= res_sen_j;
                onechrom.minres_sen.sen_no= j;
            }
        }
    }
    onechrom.indiv_res[1]=comp_poem_re(keyword,onechrom);
    finword.close();
    finrev.close();
    return 1;
}

int init_chrom(vector<vector<int> > poemindiv, Chrom &  onechrom,vector<int> keyword) 
{
    onechrom.indiv.assign(poemindiv.begin(),poemindiv.end());
    if( comp_res(keyword,onechrom)<0)
    {
        cout<< "comp_res error" <<endl;
        return -1;
    }
    return 1;
}

void crossover_chrom (Chrom&  firchrom, Chrom & secchrom,vector<int> keyword)
{
    double fir_cro_res=firchrom.minres_sen.sen_res;
    double sec_cro_res=secchrom.minres_sen.sen_res;
    double cro_res=fir_cro_res;
    int cro_sen_no=firchrom.minres_sen.sen_no;
    if(cro_res>sec_cro_res)/** 比较两首词适应度最小的句子的适应度，取更小的交叉 */
    {
        cro_res=sec_cro_res;
        cro_sen_no=secchrom.minres_sen.sen_no;
    }
    int cro_sen_len=firchrom.indiv[cro_sen_no].size(); /** 获取两者适应度最小句的句子长度 */
    int rand_sen_no=cre_random(0,firchrom.indiv.size()-1); /**为了避免频繁交叉小词数句子(因为发现小词数句子成为适应度最小的句子的概率大，原因在与小词数句子单词少，则情感得分方差大)，随机生成句子编号，以0.3的概率接受交叉这句 */
    int rand_sen_len=firchrom.indiv[rand_sen_no].size();
    double prand=cre_random(0,1);
    if ( prand<PCLEVER )
    {
        cro_sen_no=rand_sen_no;
        cro_sen_len=rand_sen_len;
    }
    int cro_sta=cre_random(0,cro_sen_len-1);    /** 随机产生部分映射交叉开始位 ,因为每句单词数过少，部分映射交叉一律交叉至本句末尾，不再随机选取结束位置*/
    vector<int> fir_cro_word;                   /** 获取确定映射的部分 */
    vector<int> sec_cro_word;
    for ( int j = cro_sta; j < cro_sen_len-1; j++ )
    {
        fir_cro_word.push_back(firchrom.indiv[cro_sen_no][j]);
        sec_cro_word.push_back(secchrom.indiv[cro_sen_no][j]);
    }
    for ( int i = 0; i < firchrom.indiv.size(); i++) /** 部分映射交叉，将全词具有映射关系的词全部交叉,交叉遵循原来映射的方向性，比如1->4，则认为4->1无效，除非本次映射其他位置存在4->1 */
    {
        for ( int k = 0; k < firchrom.indiv[i].size(); k++ )
        {
            vector<int>::iterator fir_findit=find(fir_cro_word.begin(),fir_cro_word.end(),firchrom.indiv[i][k]);
            if(fir_findit!=fir_cro_word.end())  /** 获取被交叉单词的迭代器 */
            {
                firchrom.indiv[i][k]=sec_cro_word.at(fir_findit-fir_cro_word.begin()); /** 计算其在矢量中的位置，并获取内容进行交叉 */
                secchrom.indiv[i][k]=fir_cro_word.at(fir_findit-fir_cro_word.begin());
            }
        }
    }
    comp_res(keyword,firchrom); /**  更新每条染色体*/
    comp_res(keyword,secchrom);
}


double res_sum(Chrom onechrom)
{
    double sum=0.;
    for ( int i = 0; i < ASPECT; ++i )
    {
        sum+=onechrom.indiv_res[i];
    }
    return sum;
}



int search_best(vector<Chrom > & popu)
{
    int best_chrom=0;
    double best_res=0.;
    double  cur_res;
    for ( int i = 0; i < popu.size(); i++ )
    {
        cur_res = res_sum(popu[i]);
        if(cur_res>=best_res)
        {
            best_res=cur_res;
            best_chrom=i;
        }
    }
    return best_chrom ;
}



void init_popu(vector<vector<vector<int > > >& oripopu,vector<Chrom>& orifather, vector<int> keyword) 
{
    Chrom indiv_chrom;
    vector<Chrom > tempfath;
    for ( int popuno = 0; popuno < oripopu.size(); popuno++ )
    {
        init_chrom(oripopu[popuno],indiv_chrom,keyword);
        tempfath.push_back(indiv_chrom);
    }
    partial_sort(tempfath.begin(),tempfath.begin()+POPSIZE,tempfath.end(),greatbf_af);
    orifather.assign(tempfath.begin(),tempfath.begin()+POPSIZE);
}


void chose_inher(vector<Chrom>& father,vector<Chrom>& son) 
{
    int best_res_no=search_best(father);
    son.clear();
    son.push_back(father[best_res_no]);         /** 精英主义，将该代最优个体100%遗传 */
    vector<double> rea_best_res;                /** 计算相对最优个体的相对适应度 */
    for ( int i = 0; i < father.size(); ++i )
    {
        rea_best_res.push_back(res_sum(father[i])/res_sum(father[best_res_no]));
    }
    vector<double> rea_best_res_sum(father.size()); /** 获取相对适应度的积累 */
    for ( int j = 0; j < father.size(); ++j )
    {
        rea_best_res_sum[j]=rea_best_res[j];
        for(int k=0; k < j;k++)
        {
            rea_best_res_sum[j]+=rea_best_res[k];
        }
    }
    double rea_res_total=rea_best_res_sum.back(); /** 获得适应度的积累值 */
    /** 
     * 轮盘赌算法 
     */
    double randres;                             
    while ( son.size() !=POPSIZE )       /** 保证种群内个体数量不变 */
    {
        randres=cre_random(0,rea_res_total);
        for ( int l = 0; l <father.size() ; l++ )
        {
            if(randres<=rea_best_res_sum[l]&&son.size()!=POPSIZE)
            {
                son.push_back(father[l]);
                break;
            }
        }
    }
}


int  change_dfa_one(Chrom onechrom,vector<Chrom> popu,int muta_sen_no,vector<int> keyword)
{
    ifstream finword;
    int i;
    finword.open("wordslib.data",ios::in|ios::binary); /**   wordslib.data 主要是单词列表  */
    int dfa=0;
    for (i = 0; i < popu.size() && dfa ==0;i++)
    {
        dfa=sytax_evaluate(popu[i].indiv[muta_sen_no],finword);
        if(dfa)
        {
            onechrom.indiv[muta_sen_no].assign(popu[i].indiv[muta_sen_no].begin(),popu[i].indiv[muta_sen_no].end());
            comp_res(keyword,onechrom);
            finword.close();
            return 1;
        }
    }
    finword.close();
    return -1;
}

int get_pz_fr_pat(string pattern,int wordth,string & wordpz) 
{
    char flag='/';
    vector<int> flagno;
    for(int i=0;i<pattern.size();i++)
    {
        if(pattern[i]=='/')
            flagno.push_back(i);
    }
    if(wordth==flagno.size())
    {
        int pos=pattern.find_last_of(flag);
        wordpz=pattern.substr(pos);
        return 1;
    }
    else
    {

        if(wordth<flagno.size())
        {
            int start=0;
            int over=flagno[wordth];
            if(wordth==0)
            {
                wordpz=pattern.substr(0,over);
            }
            else
            {
                start=flagno[wordth-1];
                wordpz=pattern.substr(start+1,over-start-1);
            }
            return 1;
        }
        else
        {
            cout<< "worth beyond pattern len!" <<endl;
            return -1;
        }
    }
}


int muta_sen(Chrom onechrom,int muta_sen_no,vector<int> keyword,vector<int> wordlist,int cipai)
{
    ifstream finword;
    finword.open("wordslib.data",ios::in|ios::binary); /**  1:19:45 wordslib.data 主要是单词列表  */
    ifstream finrev;
    finrev.open("reva.data",ios::in|ios::binary); /**  1:18:05 reve.data主要是两个单词之间的相关度矩阵 */

    /**
     * 选择变异位置
     */
    if(onechrom.indiv[muta_sen_no].size()==1)
        return 0;                               /** 避开单个词构成句子的变异 */
    int chos_pos=rand()%onechrom.indiv[muta_sen_no].size(); /**  随机选取句子中变异单词周围的位置（单词）*/
    int muta_pos;                               /** 变异单词所在的位置 */
    if(chos_pos==0)                             /** 当第一个单词  */
    {
        if( onechrom.indiv[muta_sen_no].size()==2) 
            muta_pos=0; /**避开如下情况：一句词由两个单词构成，该句含有韵脚，选择第一个单词，+1对韵脚进行改变 */
        else
            muta_pos=chos_pos+1;
    }
    else
    {
        muta_pos=chos_pos-1;/** 变异选中单词前面的单词 避开了替换该句的韵脚单词的可能  */
    }

    /**
     * 获取变异位置应具有的平仄
     */
    int wordid=onechrom.indiv[muta_sen_no][muta_pos]; /** 获取变异位置的单词ID */
    string sen_pattern(cipai_table[cipai].ref[muta_sen_no]); /** 获取将要变异的句子的pattern */
    string muta_pz;                             /** 将要变异的单词所占位置在pattern中的平仄 */
    if (get_pz_fr_pat(sen_pattern,muta_pos,muta_pz)==-1)
        return -1;
    /**
     * 比较变异单词与正常格律模式下该部位平仄字数的长度，只有相同的字数才能变异
     */
    int muta_len=wordid>split_one?2:1;          /** 获取被替换单词的长度 */
    if(muta_len!=muta_pz.size())
    {
        cout<<"muta_len="<<muta_len<<" muta_pz_size="<<muta_pz.size()<<endl;
        cout<< "muta_sen error!" <<endl;
        finword.close();
        finrev.close();
        return -1;
    }

    /**
     * 获取wordlist中1字单词与2字单词的分界
     */
    int fir_two_pos=0;
    sort(wordlist.begin(),wordlist.end());
    while(wordlist[fir_two_pos]<=split_one)
        fir_two_pos++;

    int start=0;
    int over=wordlist.size()-1;
    if(muta_len==1)
        over=fir_two_pos-1;
    else                                        /** muta_len==2 */
        start=fir_two_pos;

    /**
     *  从wordlist中选择合适的单词进行变异
     *  两种办法：
     *  
     *  1、使用wordlist中获得打分最高的单词去变异；缺点：一次变异太慢
     *  2、使用wordlist中第一次遇到的打分超越原词的单词变异;缺点：需要较多次迭代才能找到更好的词
     *
     */

    word new_word;
    double ori_score=re_evaluate(onechrom.indiv[muta_sen_no],keyword,finrev)/onechrom.indiv[muta_sen_no].size()*RE_TIME+emotion_evaluate(onechrom.indiv[muta_sen_no],finword)*EM_TIME;
    double try_best_score=ori_score;/** 最好的变异后宋词的打分,初始为原宋词的打分 */
    double try_score=ori_score;
    int try_best_id=wordid; /** 变异后最好单词的id,初始为原单词id */
    int try_id=wordid;
    int pz_jd=1;
    int count_muta=0;
    Chrom try_chrom=onechrom;
    vector<int > try_sen;
    try_sen.assign(onechrom.indiv[muta_sen_no].begin(),onechrom.indiv[muta_sen_no].end());
    for(int i=start;i<over;i++)
    {
        new_word=get_word(wordlist[i],finword);
        pz_jd=1;                            /** 该词与原句式该位置应有的平仄比较 */
        for(int k=0;k<muta_len;k++)
        {
            if(muta_pz[k]=='*')
                continue;
            else
            {
                if(muta_pz[k]!=new_word.pz[k])
                    pz_jd=0;
            }
        }
        if(pz_jd)                               /** 如果平仄相同 才执行如下  */
        {
            try_id=new_word.id;
            try_sen[muta_pos]=try_id;
            if(sytax_evaluate(try_sen,finword))
            {
                try_score=re_evaluate(try_sen,keyword,finrev)/try_sen.size()*RE_TIME+emotion_evaluate(try_sen,finword)*EM_TIME;
                /**
                 *  方法一
                 */
/*                 if(try_score>ori_score)
 *                 {
 *                     try_best_id=try_id;
 *                     try_best_score=try_score;
 *                     break;
 *                 }
 */


                /**
                 * 方法二 
                 */
                        if(try_score>try_best_score)
							//&&count_muta<COUNTTIME)
                        {
                            try_best_id=try_id;
                            try_best_score=try_score;
                            //count_muta++;
                        }
            }
        }
    }

    onechrom.indiv[muta_sen_no][muta_pos]=try_best_id;
    comp_res(keyword,onechrom);

    finword.close();
    finrev.close();
    if(try_best_id==wordid)
        return 0;
    else
    {
        return 1;
    }
    return -1;
}



int  muta(Chrom & onechrom,vector<Chrom> popu,vector<int > keyword,vector<int > & wordlist,int cipai)
{
    int muta_sen_no=onechrom.minres_sen.sen_no;    /**与交叉时采取0.8概率接受变异非最小适应度句子同样的操作步骤  */
    ifstream finword;
    finword.open("wordslib.data",ios::in|ios::binary); /**  wordslib.data 主要是单词列表  */
    double prand=cre_random(0,1);
    if ( prand<PCLEVER )                        /** 以0.8概率接受其他句子变异  */
    {
        muta_sen_no=cre_random(0,onechrom.indiv.size()-1);
    }
    int dfa=sytax_evaluate(onechrom.indiv[muta_sen_no],finword);
    finword.close();
    /**
     *  如果变异词句的DFA为0,则从中群内其他个体中找本句DFA为1的进行替换，否则开始变异。
     */
    if(dfa==0)
    {
        return change_dfa_one(onechrom,popu,muta_sen_no,keyword);
    }
    else
    {
        return muta_sen(onechrom,muta_sen_no,keyword,wordlist,cipai);
    }
}



int ga_pro(vector<Chrom>& father,vector<Chrom>& son, int gen,vector<int> keyword,vector<int > wordlist,int cipai)
{

#if DEBUGMODE
    time_t begin_chose_inher=time(NULL);
#endif    

    Chrom best_fa=father[search_best(father)];  /** 获取最优父代的得分，稍后与最优子代比较 */
    double best_fa_res=res_sum(best_fa);
    chose_inher(father,son);                    /** 从父代选择遗传 */

#if DEBUGMODE
    cout<<"chose_inher time : "<< time(NULL)-begin_chose_inher<<endl;
#endif

#if DEBUGMODE
    time_t begin_cross=time(NULL);
#endif    

    int fir,sec;                                /** 被选择交叉或者变异的个体编号 */
    double pxover=0.;                           /** 产生交叉的随机数 */
    double pmu;                                 /** 产生变异的随机数 */
    double pfaok;                               /** 产生接受父代的随机数 */
    Chrom  media;                               /** 暂存交叉后的个体 */
    Chrom firbak;                               /** 暂存被选择交叉前的个体 */
    Chrom secbak;                               /** 暂存被选择交叉前的个体 */

    for(int times=0;times<NOCROSS;times++)
    {
        fir=(int)cre_random(0,son.size()-1);
        sec=(int)cre_random(0,son.size()-1);
        firbak=son[fir];
        secbak=son[sec];

        pxover=cre_random(0,1);
        if(pxover<PXOVER)                       /** 0.8的概率产生交叉 */
        {
            crossover_chrom(son[fir],son[sec],keyword); /** 交叉并更新适应度 */
        }

        for ( int m = 0; m < NOMUTATION; m++ )
        {
            media=son[fir];
            pmu=cre_random(0,1);
            if(pmu<PMUTATION&&muta(son[fir],son,keyword,wordlist,cipai)!=-1)               /**即以PMUTATION的概率接受变异  */
            {
                /** 接受正变异 */
            }
            else
                son[fir]=media;   

            media=son[sec];
            pmu=cre_random(0,1);
            if(pmu<PMUTATION&&muta(son[sec],son,keyword,wordlist,cipai)!=-1)               /**即以PMUTATION的概率接受变异  */
            {
                /** 接受正变异 */
            }
            else
                son[sec]=media;   
        }
        if(res_sum(son[fir])<res_sum(firbak))
        {
            pfaok=cre_random(0,1);
            if(pfaok<PFATHEROK)
                son[fir]=firbak;
        }
        if(res_sum(son[sec])<res_sum(secbak))
        {
            pfaok=cre_random(0,1);
            if(pfaok<PFATHEROK)
                son[sec]=secbak;
        }
    }
#if DEBUGMODE
    cout<<NOCROSS<<" cross time : "<< time(NULL)-begin_cross<<endl;
#endif
    int best_son_no=search_best(son);
    double best_son_res=res_sum(son[best_son_no]);
    if(best_son_res<best_fa_res)
    {
        int rand_son=cre_random(0,son.size()-1);
        while(rand_son==best_son_no)
            rand_son=cre_random(0,son.size()-1);
        son[rand_son]=best_fa;
        best_son_no=rand_son;
        best_son_res=best_fa_res;
    }
    best_son_no=search_best(son);
#if DEBUGMODE
    cout<<"ga_pro time : "<<time(NULL)-begin_chose_inher<<endl;
#endif
	/* cout<<gen<<": the  best son no : " <<best_son_no<<" , the best son res : "<<res_sum(son[best_son_no]); 
	for(int m=0;m<ASPECT;m++)
	{
	cout<<" "<<son[best_son_no].indiv_res[m]<<" ";
	}
	cout<<endl;*/
    return best_son_no;
}




#endif

