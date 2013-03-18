#ifndef GA_H_
#define GA_H_

#include "getpoem.h"
#include <limits.h>
/**
 *     @file  ga.h
 *     @brief  GA �㷨�������� 
 *     @author  NanKor (NK), mkzmkzmkz1988@gmail.com
 *     @date  2012��11��05�� 18ʱ10��26��
 *    Compiler  gcc/g++
 *     Company  XiDian Univ
 *   Copyright  Copyright (c) 2012, NanKor
 */

using namespace std;

#define POPSIZE     200                            /**  population size ��Ⱥ��С*/ 
#define NOGEN       100                             /**  �Ŵ�����*/ 
#define PXOVER      0.8                            /**  probability of crossover �ӽ�����*/ 
#define PMUTATION   0.9                            /**  probability of mutation ������� 0.7*/ 
#define NOMUTATION  1                              /**  ����������� 1 */
#define NOCROSS     50                             /** ������� */
#define PFATHEROK   0.3                            /**  �������ܸ��� 0.3*/
#define ASPECT      3                              /**  ��Ӧ��ָ������  */
#define DEBUGMODE   0                              /** DEBUGģʽ */
#define COUNTTIME   50                             /** ����ʱѰ������ԭ�����ʵĲ���  */
#define RE_TIME     10                             /** ��ضȵ�Ȩֵ */
#define EM_TIME     1                              /** ����ʱ��з����Ȩֵ  */
#define PCLEVER     0.8                            /**  ���ڴ����ٵľ�����е÷ַ���󣬼�������Ǳ��״�����Ӧ����С�ľ��ӣ������������һֱѡ��˾䣬�ı�Ĵ������٣����Ըø��ʽ���ѡ�񽻲��������ӽ��н�����죬����������ĳ��������Ļ������г���  */
#define SHAMETIME   4
/**
 * @class sen_no_res
 * @brief ��ȡһ�״�����Ӧ����С�ľ��ӱ������Ӧ��
 */
struct sen_no_res{
    int sen_no;                                 /** �þ��0��ʼ���� */
    double sen_res;                             /** �þ�ASPECT�������Ӧ��֮�� */
};


/**
 * @class chromosome
 * @brief һ�״���ΪȾɫ����壬���������ݣ�����Ӧ�ȣ���С��Ӧ�Ⱦ���
 */
struct chromosome {
    vector<vector<int> > indiv;                 /** һ�״� */
    double  indiv_res[ASPECT];                  /** ���״��������Ӧ�� */
    struct sen_no_res  minres_sen;              /**  ���״�����С��Ӧ�ȵľ��Ӻ�����ƽ����Ӧ�� */

    /** 
     * @brief operator=  ����=����Ϊstruct��ֵ 
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
 * @brief greatbf_af  �Ƚ������������Ӧ�� before>after
 * @param  const chromosome & before,const chromosome & after
 * @return true:before>after false:before<after
 * 
 */
bool greatbf_af(const chromosome & before,const chromosome & after);


/** 
 * @brief cre_random ����[start,end]��������
 * @param double start, double end  
 * @return double �����
 * 
 */
double cre_random ( double start,double end );


/** 
 * @brief disp_poem ��ʾһ�״�����
 * @param  vector<vector<int > > onepoem
 * @return NULL
 * 
 */

void disp_poem ( vector<vector<int > > onepoem );

/** 
 * @brief disp_chrom ��ʾȾɫ������ 
 * @param  Chrom onechrom 
 * @return NULL
 * 
 */
void disp_chrom ( Chrom  onechrom);

/** 
 * @brief comp_poem_re 
 * @param vector<int> keyword, Chrom& onechrom
 * @return double ���гͷ������״��������ضȵ÷֡�10
 * 
 */
double comp_poem_re (vector<int> keyword, Chrom& onechrom);


/** 
 * @brief comp_res ����ĳ��Ⱦɫ�����Ӧ������С��Ӧ�ȵľ�������
 * @param vector<int> keyword, Chrom& onechrom
 * @return int 1 �ɹ� int -1 ʧ��
 * 
 */
int comp_res(vector<int> keyword, Chrom& onechrom);


/** 
 * @brief init_chrom ��ʼ��һ��Ⱦɫ�� 
 * @param vector<vector<int> > poemindiv, Chrom &  onechrom, vector<int> keyword 
 * @return int 1 �ɹ� int -1 ʧ��
 * 
 */
int init_chrom(vector<vector<int> > poemindiv, Chrom &  onechrom, vector<int> keyword); 


/** 
 * @brief crossover_chrom ���״�����С��Ӧ�ȵľ��ӽ��н��� 
 * @param Chrom & firchrom, Chrom & secchrom,vector<int> keyword������ĸ���
 * @return int  1 �ɹ� int -1 ʧ��
 * 
 */
void crossover_chrom (Chrom & firchrom, Chrom & secchrom,vector<int> keyword);


/** 
 * @brief search_best ѡȡ��Ⱥ�����ŵĸ��� 
 * @param  vector<Chrom > & popu
 * @return int �������Ÿ���ı�� 
 * 
 */
int search_best(vector<Chrom > & popu);


/** 
 * @brief init_popu ��ʼ����Ⱥ 
 * @param vector<vector<vector<int > > >& oripopu,vector<Chrom>& orifather, vector<int> keyword 
 * @return null 
 * 
 */
void init_popu(vector<vector<vector<int > > >& oripopu,vector<Chrom>& orifather, vector<int> keyword) ;


/** 
 * @brief chose_inher ѡ���Ŵ� 
 * @param vector<Chrom>& father,vector<Chrom>& son
 * @return NULL
 * 
 */
void chose_inher(vector<Chrom>& father,vector<Chrom>& son);

/** 
 * @brief change_dfa_one 
 * @param Chrom onechrom,vector<Chrom> popu,int muta_sen_no,vector<int> keyword
 * @return int 1 �ɹ� int -1 ʧ��
 * 
 */
int  change_dfa_one(Chrom onechrom,vector<Chrom> popu,int muta_sen_no,vector<int> keyword);


/** 
 * @brief get_pz_fr_pat ��һ��pattern�л�ȡ��wordth�����ʵ�ƽ���ַ���,wordth ��0���� 
 * @param string pattern,int wordth,string & wordpz
 * @return
 * 
 */
int get_pz_fr_pat(string pattern,int wordth,string & wordpz); 


/** 
 * @brief muat_sen ����onechrom[muta_sen_no]�е�ĳ������ 
 * @param Chrom onechrom,int muta_sen_no,vector<int> keyword,vector<int> wordlist,int cipai
 * @return int 1 �����켴�������� int 0 ����֮����Ӧ��û�仯 int -1 ������
 * 
 */
int muta_sen(Chrom onechrom,int muta_sen_no,vector<int> keyword,vector<int> wordlist,int cipai);



/** 
 * @brief muat 
 * @param Chrom & onechrom,vector<Chrom> popu,vector<int > keyword,vector<int > & wordlist,int cipai
 * @return 0 û�б��� 1 ���������dfa����ͨ�� -1���������DFA����û��ͨ��
 * 
 */
int  muta(Chrom & onechrom,vector<Chrom> popu,vector<int > keyword,vector<int > & wordlist,int cipai);


/** 
 * @brief ga_pro �Ŵ��㷨���� 
 * @param vector<Chrom>& father,vector<Chrom>& son, int gen,vector<int> keyword,vector<int> wordlist 
 * @return �����Ӵ��ı��
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
    finrev.open("reva.data",ios::in|ios::binary); /**  wordslib.data ��Ҫ�ǵ����б�  */
    double poem_re=0.;
    int j=0;
    for ( j = 0; j < onechrom.indiv.size(); j++ )
    {
        poem_re += re_evaluate(onechrom.indiv[j],keyword,finrev); /**  ����ʵ�������ض����� */
    }

    /**
     *  ����ĳ�״�����Ϊʹ�ö���ظ��Ĵʣ����гͷ����Ա�����ʹ���ظ�����ɵ�
     *  ��ض�����е÷ֵ�����
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
    int count_re=0;                             /** ����һ�״��������ظ����ظ��Ĵ��� */
    for(int i=1;i<poem_sort.size();i++)
    {
        if(poem_sort[i]==poem_sort[i-1])
            count_re++;
    }
    double aver_re=poem_re/poem_sort.size();
    poem_re=aver_re*(poem_sort.size()-count_re*SHAMETIME)*RE_TIME; /** SHAMETIME���ͷ��ظ��� */
    finrev.close();
    return poem_re;
}


int comp_res(vector<int> keyword, Chrom& onechrom)
{
    ifstream finrev;
    finrev.open("reva.data",ios::in|ios::binary); /**  reve.data��Ҫ����������֮�����ضȾ��� */
    ifstream finword;
    finword.open("wordslib.data",ios::in|ios::binary); /**   wordslib.data ��Ҫ�ǵ����б�  */
    double res_sen_j=0.,sen_syta=0.,sen_re=0.,sen_emo=0.; 
    /** res_sen_j��¼��ǰ���ӵĵ÷� 
     * sen_syta��¼��ǰ���ӵ��﷨���۵ĺ������ 
     * sen_emo��¼��ǰ���ӵ�������ۺ����Ľ��
     * sen_re ��¼��ǰ���ӵ���������ضȵĺ������۽��
     */

    int j=0;
    for ( j=0;j < onechrom.indiv.size(); j++ )   /** �������״��ڵ�ÿ�� */
    {
        res_sen_j=0.;
        for ( int i = 0; i< ASPECT; i++ )       /** ����ÿ����ASPECT����������۽�� ����ø��״��ܵ���Ӧ�� */
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
                    sen_syta = sytax_evaluate(onechrom.indiv[j],finword); /** ��ȡ������﷨��ȷ�� ����֤DFA ͨ��Ϊ1 ����Ϊ0 */
                    onechrom.indiv_res[i] +=sen_syta;
                    res_sen_j +=sen_syta;
                    break;
                case 1:
                    sen_re =  re_evaluate(onechrom.indiv[j],keyword,finrev); /**  ����ʵ�������ض����� */
                    res_sen_j += (sen_re/onechrom.indiv[j].size()); /** ����ÿ��ĵ�����Ŀ��һ����������Ըþ��������ƽ����ض� */
                    break;
                case 2:
                    sen_emo = emotion_evaluate(onechrom.indiv[j],finword); /**  ����ʵ����ͳһ�� */
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
        /** ȡ�ø��״�����Ӧ����С�ľ��ӱ������Ӧ���ӵ���Ӧ�� */
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
    if(cro_res>sec_cro_res)/** �Ƚ����״���Ӧ����С�ľ��ӵ���Ӧ�ȣ�ȡ��С�Ľ��� */
    {
        cro_res=sec_cro_res;
        cro_sen_no=secchrom.minres_sen.sen_no;
    }
    int cro_sen_len=firchrom.indiv[cro_sen_no].size(); /** ��ȡ������Ӧ����С��ľ��ӳ��� */
    int rand_sen_no=cre_random(0,firchrom.indiv.size()-1); /**Ϊ�˱���Ƶ������С��������(��Ϊ����С�������ӳ�Ϊ��Ӧ����С�ľ��ӵĸ��ʴ�ԭ������С�������ӵ����٣�����е÷ַ����)��������ɾ��ӱ�ţ���0.3�ĸ��ʽ��ܽ������ */
    int rand_sen_len=firchrom.indiv[rand_sen_no].size();
    double prand=cre_random(0,1);
    if ( prand<PCLEVER )
    {
        cro_sen_no=rand_sen_no;
        cro_sen_len=rand_sen_len;
    }
    int cro_sta=cre_random(0,cro_sen_len-1);    /** �����������ӳ�佻�濪ʼλ ,��Ϊÿ�䵥�������٣�����ӳ�佻��һ�ɽ���������ĩβ���������ѡȡ����λ��*/
    vector<int> fir_cro_word;                   /** ��ȡȷ��ӳ��Ĳ��� */
    vector<int> sec_cro_word;
    for ( int j = cro_sta; j < cro_sen_len-1; j++ )
    {
        fir_cro_word.push_back(firchrom.indiv[cro_sen_no][j]);
        sec_cro_word.push_back(secchrom.indiv[cro_sen_no][j]);
    }
    for ( int i = 0; i < firchrom.indiv.size(); i++) /** ����ӳ�佻�棬��ȫ�ʾ���ӳ���ϵ�Ĵ�ȫ������,������ѭԭ��ӳ��ķ����ԣ�����1->4������Ϊ4->1��Ч�����Ǳ���ӳ������λ�ô���4->1 */
    {
        for ( int k = 0; k < firchrom.indiv[i].size(); k++ )
        {
            vector<int>::iterator fir_findit=find(fir_cro_word.begin(),fir_cro_word.end(),firchrom.indiv[i][k]);
            if(fir_findit!=fir_cro_word.end())  /** ��ȡ�����浥�ʵĵ����� */
            {
                firchrom.indiv[i][k]=sec_cro_word.at(fir_findit-fir_cro_word.begin()); /** ��������ʸ���е�λ�ã�����ȡ���ݽ��н��� */
                secchrom.indiv[i][k]=fir_cro_word.at(fir_findit-fir_cro_word.begin());
            }
        }
    }
    comp_res(keyword,firchrom); /**  ����ÿ��Ⱦɫ��*/
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
    son.push_back(father[best_res_no]);         /** ��Ӣ���壬���ô����Ÿ���100%�Ŵ� */
    vector<double> rea_best_res;                /** ����������Ÿ���������Ӧ�� */
    for ( int i = 0; i < father.size(); ++i )
    {
        rea_best_res.push_back(res_sum(father[i])/res_sum(father[best_res_no]));
    }
    vector<double> rea_best_res_sum(father.size()); /** ��ȡ�����Ӧ�ȵĻ��� */
    for ( int j = 0; j < father.size(); ++j )
    {
        rea_best_res_sum[j]=rea_best_res[j];
        for(int k=0; k < j;k++)
        {
            rea_best_res_sum[j]+=rea_best_res[k];
        }
    }
    double rea_res_total=rea_best_res_sum.back(); /** �����Ӧ�ȵĻ���ֵ */
    /** 
     * ���̶��㷨 
     */
    double randres;                             
    while ( son.size() !=POPSIZE )       /** ��֤��Ⱥ�ڸ����������� */
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
    finword.open("wordslib.data",ios::in|ios::binary); /**   wordslib.data ��Ҫ�ǵ����б�  */
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
    finword.open("wordslib.data",ios::in|ios::binary); /**  1:19:45 wordslib.data ��Ҫ�ǵ����б�  */
    ifstream finrev;
    finrev.open("reva.data",ios::in|ios::binary); /**  1:18:05 reve.data��Ҫ����������֮�����ضȾ��� */

    /**
     * ѡ�����λ��
     */
    if(onechrom.indiv[muta_sen_no].size()==1)
        return 0;                               /** �ܿ������ʹ��ɾ��ӵı��� */
    int chos_pos=rand()%onechrom.indiv[muta_sen_no].size(); /**  ���ѡȡ�����б��쵥����Χ��λ�ã����ʣ�*/
    int muta_pos;                               /** ���쵥�����ڵ�λ�� */
    if(chos_pos==0)                             /** ����һ������  */
    {
        if( onechrom.indiv[muta_sen_no].size()==2) 
            muta_pos=0; /**�ܿ����������һ������������ʹ��ɣ��þ京���Ͻţ�ѡ���һ�����ʣ�+1���ϽŽ��иı� */
        else
            muta_pos=chos_pos+1;
    }
    else
    {
        muta_pos=chos_pos-1;/** ����ѡ�е���ǰ��ĵ��� �ܿ����滻�þ���Ͻŵ��ʵĿ���  */
    }

    /**
     * ��ȡ����λ��Ӧ���е�ƽ��
     */
    int wordid=onechrom.indiv[muta_sen_no][muta_pos]; /** ��ȡ����λ�õĵ���ID */
    string sen_pattern(cipai_table[cipai].ref[muta_sen_no]); /** ��ȡ��Ҫ����ľ��ӵ�pattern */
    string muta_pz;                             /** ��Ҫ����ĵ�����ռλ����pattern�е�ƽ�� */
    if (get_pz_fr_pat(sen_pattern,muta_pos,muta_pz)==-1)
        return -1;
    /**
     * �Ƚϱ��쵥������������ģʽ�¸ò�λƽ�������ĳ��ȣ�ֻ����ͬ���������ܱ���
     */
    int muta_len=wordid>split_one?2:1;          /** ��ȡ���滻���ʵĳ��� */
    if(muta_len!=muta_pz.size())
    {
        cout<<"muta_len="<<muta_len<<" muta_pz_size="<<muta_pz.size()<<endl;
        cout<< "muta_sen error!" <<endl;
        finword.close();
        finrev.close();
        return -1;
    }

    /**
     * ��ȡwordlist��1�ֵ�����2�ֵ��ʵķֽ�
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
     *  ��wordlist��ѡ����ʵĵ��ʽ��б���
     *  ���ְ취��
     *  
     *  1��ʹ��wordlist�л�ô����ߵĵ���ȥ���죻ȱ�㣺һ�α���̫��
     *  2��ʹ��wordlist�е�һ�������Ĵ�ֳ�Խԭ�ʵĵ��ʱ���;ȱ�㣺��Ҫ�϶�ε��������ҵ����õĴ�
     *
     */

    word new_word;
    double ori_score=re_evaluate(onechrom.indiv[muta_sen_no],keyword,finrev)/onechrom.indiv[muta_sen_no].size()*RE_TIME+emotion_evaluate(onechrom.indiv[muta_sen_no],finword)*EM_TIME;
    double try_best_score=ori_score;/** ��õı�����δʵĴ��,��ʼΪԭ�δʵĴ�� */
    double try_score=ori_score;
    int try_best_id=wordid; /** �������õ��ʵ�id,��ʼΪԭ����id */
    int try_id=wordid;
    int pz_jd=1;
    int count_muta=0;
    Chrom try_chrom=onechrom;
    vector<int > try_sen;
    try_sen.assign(onechrom.indiv[muta_sen_no].begin(),onechrom.indiv[muta_sen_no].end());
    for(int i=start;i<over;i++)
    {
        new_word=get_word(wordlist[i],finword);
        pz_jd=1;                            /** �ô���ԭ��ʽ��λ��Ӧ�е�ƽ�ƱȽ� */
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
        if(pz_jd)                               /** ���ƽ����ͬ ��ִ������  */
        {
            try_id=new_word.id;
            try_sen[muta_pos]=try_id;
            if(sytax_evaluate(try_sen,finword))
            {
                try_score=re_evaluate(try_sen,keyword,finrev)/try_sen.size()*RE_TIME+emotion_evaluate(try_sen,finword)*EM_TIME;
                /**
                 *  ����һ
                 */
/*                 if(try_score>ori_score)
 *                 {
 *                     try_best_id=try_id;
 *                     try_best_score=try_score;
 *                     break;
 *                 }
 */


                /**
                 * ������ 
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
    int muta_sen_no=onechrom.minres_sen.sen_no;    /**�뽻��ʱ��ȡ0.8���ʽ��ܱ������С��Ӧ�Ⱦ���ͬ���Ĳ�������  */
    ifstream finword;
    finword.open("wordslib.data",ios::in|ios::binary); /**  wordslib.data ��Ҫ�ǵ����б�  */
    double prand=cre_random(0,1);
    if ( prand<PCLEVER )                        /** ��0.8���ʽ����������ӱ���  */
    {
        muta_sen_no=cre_random(0,onechrom.indiv.size()-1);
    }
    int dfa=sytax_evaluate(onechrom.indiv[muta_sen_no],finword);
    finword.close();
    /**
     *  �������ʾ��DFAΪ0,�����Ⱥ�������������ұ���DFAΪ1�Ľ����滻������ʼ���졣
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

    Chrom best_fa=father[search_best(father)];  /** ��ȡ���Ÿ����ĵ÷֣��Ժ��������Ӵ��Ƚ� */
    double best_fa_res=res_sum(best_fa);
    chose_inher(father,son);                    /** �Ӹ���ѡ���Ŵ� */

#if DEBUGMODE
    cout<<"chose_inher time : "<< time(NULL)-begin_chose_inher<<endl;
#endif

#if DEBUGMODE
    time_t begin_cross=time(NULL);
#endif    

    int fir,sec;                                /** ��ѡ�񽻲���߱���ĸ����� */
    double pxover=0.;                           /** �������������� */
    double pmu;                                 /** �������������� */
    double pfaok;                               /** �������ܸ���������� */
    Chrom  media;                               /** �ݴ潻���ĸ��� */
    Chrom firbak;                               /** �ݴ汻ѡ�񽻲�ǰ�ĸ��� */
    Chrom secbak;                               /** �ݴ汻ѡ�񽻲�ǰ�ĸ��� */

    for(int times=0;times<NOCROSS;times++)
    {
        fir=(int)cre_random(0,son.size()-1);
        sec=(int)cre_random(0,son.size()-1);
        firbak=son[fir];
        secbak=son[sec];

        pxover=cre_random(0,1);
        if(pxover<PXOVER)                       /** 0.8�ĸ��ʲ������� */
        {
            crossover_chrom(son[fir],son[sec],keyword); /** ���沢������Ӧ�� */
        }

        for ( int m = 0; m < NOMUTATION; m++ )
        {
            media=son[fir];
            pmu=cre_random(0,1);
            if(pmu<PMUTATION&&muta(son[fir],son,keyword,wordlist,cipai)!=-1)               /**����PMUTATION�ĸ��ʽ��ܱ���  */
            {
                /** ���������� */
            }
            else
                son[fir]=media;   

            media=son[sec];
            pmu=cre_random(0,1);
            if(pmu<PMUTATION&&muta(son[sec],son,keyword,wordlist,cipai)!=-1)               /**����PMUTATION�ĸ��ʽ��ܱ���  */
            {
                /** ���������� */
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

