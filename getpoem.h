/**
 * @file getpoem.h
 * @brief	��ʼ��Ⱥ����
 * @author li shuangjiang
 * @version 1.0.0
 * @date 2012-11-05
 */

#ifndef GTEPOEM_H_
#define GETPOEM_H_
#include "def.h"
#define NOPOEM 500

/**
 * @brief	�ж�3�־��Ƿ�����﷨�ṹ
 *
 * @param	sentence	���ж�����
 * @param	fin	wordslib.data������������
 *
 * @return	�ж�����������﷨Ϊ1���������﷨Ϊ0	
 */
int sytax_3(vector<int>& sentence,ifstream& fin)
{
	//���־����ֽṹ1/2,2/1
	//�﷨�ṹ�� n+v,n+a,d+v,a+n,v+n
	word word1 = get_word(sentence[0],fin);
	word word2 = get_word(sentence[1],fin);
	//n+n,n+v,n+a
	if((word1.cx & 1U) && (word2.cx & 7U))
	{
		return 1;
	}
	//d+v
	if((word1.cx & 8U) && (word2.cx & 2U))
	{
		return 1;
	}
	//a+n
	if((word1.cx & 4U) && (word2.cx & 1U))
	{
		return 1;
	}
	//v+n
	if((word1.cx & 2U) && (word2.cx && 1U))
	{
		return 1;
	}
	
	return 0;
}
//�ж�4�־��Ƿ�����﷨�ṹ
/**
 * @brief	�ж�4�־��Ƿ�����﷨�ṹ
 *
 * @param	sentence	���ж��ľ���
 * @param	fin	wordslib.data������������
 *
 * @return	�ж�����������﷨Ϊ1���������﷨Ϊ0	
 */
int sytax_4(vector<int>& sentence,ifstream& fin)
{
	//���־�ĽṹΪ2/2
	//�ṹͬ3�־�,���n+n�ṹ
	word word1 = get_word(sentence[0],fin);
	word word2 = get_word(sentence[1],fin);
	//n+n,n+v,n+a
	if((word1.cx & 1U) && (word2.cx & 7U))
	{
		return 1;
	}
	//d+v
	if((word1.cx & 8U) && (word2.cx & 2U))
	{
		return 1;
	}
	//a+n
	if((word1.cx & 4U) && (word2.cx & 1U))
	{
		return 1;
	}
	//v+n
	if((word1.cx & 2U) && (word2.cx && 1U))
	{
		return 1;
	}
	
	return 0;
}
/**
 * @brief	�ж�5�־��Ƿ�����﷨�ṹ
 *
 * @param	sentence	���ж��ľ���
 * @param	fin	wordslib.data������������
 *
 * @return	�ж�����������﷨Ϊ1���������﷨Ϊ0	
 */
int sytax_5(vector<int>& sentence,ifstream& fin)
{
	//5�־������ֽṹ2/1/2,2/2/1
	//�﷨�ṹΪn+n+n,n+n+v,n+n+a,n+v+n,n+v+d,v+n+n
	word word1 = get_word(sentence[0],fin);
	word word2 = get_word(sentence[1],fin);
	word word3 = get_word(sentence[2],fin);
	//n+n+n,n+n+a,n+n+v
	if((word1.cx & 1U) && (word2.cx & 1U) && (word3.cx & 7U))
	{
		return 1;
	}
	//n+v+n,n+v+d
	if((word1.cx & 1U) && (word2.cx & 2U) && (word3.cx & 9U))
	{
		return 1;
	}
	//v+n+n
	if((word1.cx & 2U) && (word2.cx & 1U) && (word3.cx & 1U))
	{
		return 1;
	}
	return 0;
}
/**
 * @brief	�ж�6�־��Ƿ�����﷨�ṹ
 *
 * @param	sentence	���ж��ľ���
 * @param	fin	wordslib.data������������
 *
 * @return	�ж�����������﷨Ϊ1���������﷨Ϊ0	
 */
int sytax_6(vector<int>& sentence,ifstream& fin)
{
	//6�־�ֻ��һ�ֽṹ2/2/2
	//�ṹͬ5�־�
	return sytax_5(sentence,fin);
}
/**
 * @brief	�ж�7�־��Ƿ�����﷨�ṹ
 *
 * @param	sentence	���ж��ľ���
 * @param	fin	wordslib.data������������
 *
 * @return	�ж�����������﷨Ϊ1���������﷨Ϊ0	
 */
int sytax_7(vector<int>& sentence,ifstream& fin)
{
	//7�־������ֽṹ2/2/1/2��2/2/2/1
	//�ṹ�� n+n+n+v,n+n+n+a,n+n+d+v,n+n+a+n,n+v+n+n,n+v+n+v,n+a+n+a,a+n+a+n,a+n+d+v,a+n+v+n

	word word1 = get_word(sentence[0],fin);
	word word2 = get_word(sentence[1],fin);
	word word3 = get_word(sentence[2],fin);
	word word4 = get_word(sentence[3],fin);
	//n+n+n+v,n+n+n+a,n+n+d+v,n+n+a+n
	if((word1.cx & 1U) && (word2.cx & 1U))
	{
		if((word3.cx & 1U) && (word4.cx & 6U))
		{
			return 1;
		}
		if((word3.cx & 8U) && (word4.cx & 2U))
		{
			return 1;
		}
		if((word3.cx & 4U) && (word4.cx & 1U))
		{
			return 1;
		}
	}
	//n+v+n+n,n+v+n+v
	if((word1.cx & 1U) && (word2.cx & 2U) && (word3.cx & 1U) && (word4.cx & 3U))
	{
		return 1;
	}
	//n+a+n+a
	if((word1.cx & 1U) && (word2.cx & 4U) && (word3.cx & 1U) && (word4.cx &4U))
	{
		return 1;
	}
	//a+n+a+n,a+n+d+v,a+n+v+n
	if((word1.cx & 4U) && (word2.cx & 1U))
	{
		if((word3.cx & 4U) && (word4.cx & 1U))
		{
			return 1;
		}
		if((word3.cx & 8U) && (word4.cx & 2U))
		{
			return 1;
		}
		if((word3.cx & 2U) && (word4.cx & 1U))
		{
			return 1;
		}
	}
	return 0;
	
}

//�﷨��ȷ�����ۺ��������о����Ƿ�����﷨���򣬷����򷵻�1�������Ϸ���0
//sentenceΪ���ж��Ĵʾ�,finΪ�򿪶������ļ�wordslib.data����
/**
 * @brief	�﷨��ȷ�����ۺ��������о����Ƿ�����﷨���򣬷����򷵻�1�������Ϸ���0
 *
 * @param	sentence	���ж��ľ���
 * @param	fin	wordslib.data�������ļ�������
 *
 * @return	�����򷵻�1�������Ϸ���0
 */
int sytax_evaluate(vector<int>& sentence,ifstream& fin)
{
	int length=sentence.size();
	int res;
	switch(length)
	{
		case 3:
			res = sytax_3(sentence,fin);
			break;
		case 4:
			res = sytax_4(sentence,fin);
			break;
		case 5:
			res = sytax_5(sentence,fin);
			break;
		case 6:
			res += sytax_6(sentence,fin);
			break;
		case 7:
			res += sytax_7(sentence,fin);
			break;
		default:
			res = 0; 
	}
	return res;
}

/**
 * @brief	��������Ե÷����ۺ���,����ָ�꣬������ÿ����ͬ�����֮��������֮�ͣ��Լ����ڴ�֮��������֮��
 *
 * @param	sentence	���ж��ľ������
 * @param	keyword		�����ID
 * @param	rvaluein	reva.data�ļ�������������
 *
 * @return	��������Ե÷�
 */
float re_evaluate(vector<int>& sentence,vector<int> keyword,ifstream& rvaluein)
{
    float value1=0;
    float value2=0;
    //float value3=0;
    int front_word=sentence[0];
    int back_word=front_word;
	for(size_t k=0;k<keyword.size();k++)
    {
        value2 += get_re_value(sentence[0],keyword[k],rvaluein);
	}
    for(size_t i=1;i<sentence.size();i++)
    {
		front_word = sentence[i];
        value1 += get_re_value(back_word,front_word,rvaluein);
        for(size_t k=0;k<keyword.size();k++)
        {
           value2 += get_re_value(sentence[i],keyword[k],rvaluein);
        }
    }
    return value1+value2/keyword.size();
}

/**
 * @brief	������������ۺ��������ظ��������д������ֵ����ĵ���
 *
 * @param	sentence	�����۵ľ���
 * @param	fin	wordslib.data�ļ�������������
 *
 * @return	������е÷�	
 */
float emotion_evaluate(vector<int>& sentence,ifstream& fin)
{
	int* qg = new int[sentence.size()];
	float avg_qg = 0;
	word temp;
	for(size_t i=0;i<sentence.size();i++)
	{
		temp = get_word(sentence[i],fin);
		qg[i] = (int)temp.qg;
		avg_qg += qg[i];
	}
	avg_qg = avg_qg/sentence.size();
	float res = 0 ;
	for(size_t i=0; i<sentence.size();i++)
	{
		res += pow((qg[i] - avg_qg),2);
	}
	res = 1/(res+1);
	delete[] qg;
	return res;
}

/**
 * @brief	�Ӻ�ѡ�ʴʱ��а�����ƽ������ģʽ���ѡ�����ɴ�
 *
 * @param	length	Ҫѡ�Ĵʵĳ���
 * @param	pattern	Ҫѡ�ʵ�ƽ������ģʽ
 * @param	wordlist	��ѡ�ʴʱ�
 * @param	sp	ָ�룬ָ��wordslib.data�в�ͬ���ȴʵ�id��Χ
 * @param	fin	wordslib.data�ļ�������������
 * @param	colored	���wordslib.data��ÿ���ʵ���ɫ����ӳ�ô��Ƿ��Ѿ�ѡ��
 *
 * @return	ѡ�дʵ�id
 */
int get_random_word(int length,string pattern,vector<int>& wordlist,int* sp,ifstream& fin,bool* colored)
{
    int id=0;
    word w;
    int max_num=0;
    int count=0;
    if(length==1)
    {
        max_num=sp[0];
    }
    else
    {
        max_num=sp[length-1]-sp[length-2];
    }
    again1:
    if(length==1)
    {
        id=rand()%sp[0];
    }
    else
    {
        id=rand()%(sp[length-1]-sp[length-2]);
        id+=sp[length-2];
    }
    if(colored[wordlist[id]])
    {
        goto again1;
    }
    count++;
    //int m=wordlist[id];
    w=get_word(wordlist[id],fin);
    if(count<max_num)
    {
        for(int i=0;i<length;i++)
        {
            if(pattern[i]!='*')
            {
                if(pattern[i]!=w.pz[i])
                {
                    goto again1;
                }
            }
        }
    }
    return id;
}

/**
 * @brief	�Ӻ�ѡ�ʴʱ��а�����ƽ������ģʽ���ѡ������ϽŴ���ɴ�
 *
 * @param	length	Ҫѡ�Ĵʵĳ���
 * @param	pattern	Ҫѡ�ʵ�����ģʽ
 * @param	wordlist	��ѡ�ʴʱ�
 * @param	sp	ָ�룬ָ��wordslib.data�в�ͬ���ȴʵ�id��Χ
 * @param	fin	wordslib.data�ļ�������������
 * @param	colored	���wordslib.data��ÿ���ʵ���ɫ����ӳ�ô��Ƿ��Ѿ�ѡ��
 * @param	yunjiao	��ѡ�ʵ��Ͻ�ID
 *
 * @return	ѡ�дʵ�id
 */
int get_random_word(int length,string pattern,vector<int>& wordlist,int* sp,ifstream& fin,bool* colored,int yunjiao)
{
    int id=0;
    word w;
    int max_num=0;
    int count=0;
    if(length==1)
    {
        max_num=sp[0];
    }
    else
    {
        max_num=sp[length-1]-sp[length-2];
    }
    again2:
    if(length==1)
    {
        id=rand()%sp[0];
    }
    else
    {
        id=rand()%(sp[length-1]-sp[length-2]);
        id+=sp[length-2];
    }
    if(colored[wordlist[id]])
    {
        goto again2;
    }
    count++;
    //int m=wordlist[id];
    w=get_word(wordlist[id],fin);
    if(count<max_num)
    {
        if((int)w.yj!=yunjiao)
        {
            goto again2;
        }
        for(int i=0;i<length;i++)
        {
            if(pattern[i]!='*')
            {
                if(pattern[i]!=w.pz[i])
                {
                    goto again2;
                }
            }
        }
    }
    return id;
}

/**
 * @brief	��ȡ������ؼ�������Դ���k��һ���Ͷ����ʱ����ٰ���max����������������BFS����������
 *
 * @param	k	��ض���ֵ
 * @param	max	��ѡ�ʵ�����
 * @param	length	��ѡ�ʵĳ���
 * @param	wordlist	���صĴ�ѡ�ʴʱ�
 * @param	colored	���wordslib.data�еĴ����Ƿ��Ѿ���ѡ���
 * @param	fin	reva.data�ļ��Ķ�����������
 *
 * @return	ѡ���Ƿ�ɹ�
 */
bool getwordslist(float k,size_t max,int length,vector<int>& wordlist,bool* colored,ifstream& fin)
{
    if(fin)
    {
        size_t count_old =wordlist.size();
        for(size_t i=0;i<count_old;i++)
        {
            if(!colored[wordlist[i]])
            {
                float* words=new float[num_word];
                fin.seekg(wordlist[i]*num_word*sizeof(float),ios::beg);
                fin.read((char*)words,num_word*sizeof(float));
                int begin=0;
                int end=0;
                if(length==1)
                {
                    begin=0;
                    end=split_one;
                }
                else if(length==2)
                {
                    begin=split_one+1;
                    end=split_two;
                }
                for(int j=begin;j<=end;j++)
                {
                    if(words[j]>=k)
                    {
                        //�жϱ��Ϊj�Ĵ��Ƿ��Ѿ���list��,���������list
						vector<int>::iterator findit = find(wordlist.begin(),wordlist.end(),j);

                        if(findit==wordlist.end())
                        {
                             wordlist.push_back(j);
                        }
                    }
                }
                delete[] words;
            }
			else
			{
				continue;
			}
            colored[wordlist[i]]=true;
            if(wordlist.size()>max)
            {
                return true;
            }
        }
        int count_new=wordlist.size();
        if(count_new==count_old)
        {
            return true;
        }
        else
        {
            return getwordslist(k,max,length,wordlist,colored,fin);
        }

    }
    else
    {
        return false;
    }
}

/**
 * @brief	�ں�ѡ�ʴʱ���ѡ�������ϽŵĴ�������Ͻű�
 *
 * @param	wordlist	��ѡ�ʴʱ�
 * @param	yjlist	ѡ�еĴʹ��ɵ��Ͻű�
 * @param	fin	wordslib.data��������
 * @param	length	Ҫѡ��ʵĴʳ�
 * @param	yunjiao	Ҫѡ���������Ͻ�ID
 * @param	sp	wordslib.data�и���ͬ�ʳ���id��Χ
 */
void getyjlist(vector<int>& wordlist,vector<int>& yjlist,ifstream& fin,int length,int yunjiao,int* sp)
{
    word w;
    int begin=0;
    int end=0;
    if(length==1)
    {
        begin=0;
        end=sp[0];
    }
    else
    {
        begin=sp[length-2];
        end=sp[length-1];
    }
    for(int i=begin;i<end;i++)
    {
        w=get_word(wordlist[i],fin);
        if(w.yj==yunjiao)
        {
            yjlist.push_back(i);
        }
    }
}
/**
 * @brief	���ݴʱ��еĴʺ͸���������ģʽ�Լ��Ͻ������ϳ�����
 *
 * @param	pattern	Ҫ���ɾ��ӵ�ƽ�Ƹ���ģʽ
 * @param	sentence	���صľ���
 * @param	wordlist	��ѡ�ʴʱ�
 * @param	fin	wordslib.data����������
 * @param	yunjiao	Ҫ���ɾ��ӵ��Ͻ�
 * @param	sp	wordslib.data�и���ͬ�ʳ���id��Χ
 * @param	colored	����ù��Ĵ�
 */
void getsentence(string pattern,vector<int>& sentence,vector<int>& wordlist,ifstream& fin,int yunjiao,int* sp,bool* colored)
{
    size_t pos=pattern.find('/');
    if(pos!=string::npos)
    {
        int word=get_random_word(pos,pattern.substr(0,pos),wordlist,sp,fin,colored);
        sentence.push_back(wordlist[word]);
        colored[wordlist[word]]=true;
        getsentence(pattern.substr(pos+1),sentence,wordlist,fin,yunjiao,sp,colored);
    }
}

/**
 * @brief	�����ӵ��ϽŲ���
 *
 * @param	length	�ϽŴʵĳ���
 * @param	pattern	Ҫ����ϽŴʵ�ƽ�Ƹ���ģʽ
 * @param	wordlist	��ѡ�ʴʱ�
 * @param	sentence	���ص��Ͻ���õľ���
 * @param	yjlist	��ѡ�ϽŴ��б�
 * @param	fin	wordslib.data����������
 * @param	colored	����ù��Ĵ�
 */
void setyj(int length,string pattern,vector<int>& wordlist,vector<int>& sentence,vector<int>& yjlist,ifstream& fin,bool* colored)
{
    int id=0;
    word w;
    size_t count=0;
    again2:
    id=rand()%yjlist.size();
    if(colored[wordlist[yjlist[id]]])
    {
        goto again2;
    }
    count++;
    w=get_word(wordlist[yjlist[id]],fin);
    if(w.pz[length-1]=='*' || count>yjlist.size() || w.pz[length-1]==pattern[length-1])
    {
        sentence.push_back(wordlist[yjlist[id]]);
        colored[wordlist[yjlist[id]]]=true;
    }
    else
    {
        goto again2;
    }
	
}

/**
 * @brief	���ݸ����Ĵ��ƣ��ؼ��ʣ���ѡ�ʴʱ������ϳ�������ɺ��ϽŵĴ�	
 *
 * @param	cipai	�����Ĵ���ID
 * @param	keyword	�����Ĺؼ���ID
 * @param	wordlist	��ѡ�ʴʱ�
 * @param	poem	���ص����ɵ��δ�
 */
void getpoem(int cipai,vector<int>& keyword,vector<int> & wordlist,vector<vector<vector<int> > > &poem)
{
	srand(time(NULL));
    float k=0.01;
    int max=200;
        wordlist.assign(keyword.begin(),keyword.end());
    bool colored[num_word];
    memset(colored,0,sizeof(bool)*num_word);
    ifstream rvaluein;
    int sp[2];
    rvaluein.open(reva_data_path,ios::in|ios::binary);
    ifstream wordslibin;
    wordslibin.open(wordslib_data_path,ios::in|ios::binary);

    //������ѡ�ʱ�
    getwordslist(k,max,1,wordlist,colored,rvaluein);
    sp[0]=wordlist.size();
    memset(colored,0,sizeof(bool)*num_word);
    max=sp[0]+300;
    getwordslist(k,max,2,wordlist,colored,rvaluein);
    sp[1]=wordlist.size();
    memset(colored,0,sizeof(bool)*num_word);
    sp[0]=sp[0]-keyword.size();
    sort(wordlist.begin(),wordlist.end());

    //cout<<sp[0]<<" "<<sp[1]<<" "<<sp[2]<<" "<<sp[3]<<endl;
	vector<string> pattern;
	for(int i=0;i<cipai_table[cipai].length;i++)
	{
		string s(cipai_table[cipai].ref[i]);
		pattern.push_back(s);
	}
    begin1:
	int yunjiao1=rand()%14+1;

	//yunjiao1=1;

    vector<int> yjlist[4];
   
	getyjlist(wordlist,yjlist[0],wordslibin,1,yunjiao1,sp);
	if(yjlist[0].size()<5)
	{
		yjlist[0].erase(yjlist[0].begin());
		goto begin1;
	}
    getyjlist(wordlist,yjlist[1],wordslibin,2,yunjiao1,sp);
	if(yjlist[1].size()<5)
	{
		yjlist[0].erase(yjlist[0].begin());
		yjlist[1].erase(yjlist[1].begin());
		goto begin1;
	}
	begin2:
    int yunjiao2=rand()%14+1;

	
    if (yunjiao2==yunjiao1)
    {
        goto begin2;
    }
    getyjlist(wordlist,yjlist[2],wordslibin,1,yunjiao2,sp);
	if(yjlist[2].size()<10)
	{
		yjlist[2].erase(yjlist[2].begin());
		goto begin2;
	}
    getyjlist(wordlist,yjlist[3],wordslibin,2,yunjiao2,sp);
	if(yjlist[3].size()<10)
	{
		yjlist[2].erase(yjlist[2].begin());
		yjlist[3].erase(yjlist[3].begin());
		goto begin2;
	}
//    cout<<sp[0]<<" "<<sp[1]<<endl;
//    for(int i=0;i<4;i++)
//    {
//        cout<<yjlist[i].size()<<" ";
//    }
//    cout<<endl;
//	cout<<yunjiao1<<" "<<yunjiao2<<endl;
    //int ret=0;
    //float value=0;
    for(int count=0;count<NOPOEM;count++)
    {
        memset(colored,0,sizeof(bool)*num_word);
        vector<vector<int> > temp;
        for(size_t i=0;i<pattern.size()/2;i++)
        {
            int last=pattern[i].find_last_of('/');
            vector<int> sentence;
            int length=pattern[i].size()-1-last;
            setyj(length,pattern[i].substr(last+1),wordlist,sentence,yjlist[length-1],wordslibin,colored);
            getsentence(pattern[i],sentence,wordlist,wordslibin,yunjiao1,sp,colored);
			sentence.push_back(sentence[0]);
            sentence.erase(sentence.begin());
            temp.push_back(sentence);
			
        }

        for(size_t i=pattern.size()/2;i<pattern.size();i++)
        {
            int last=pattern[i].find_last_of('/');
            vector<int> sentence;
            int length=pattern[i].size()-1-last;
            setyj(length,pattern[i].substr(last+1),wordlist,sentence,yjlist[length+1],wordslibin,colored);
            getsentence(pattern[i],sentence,wordlist,wordslibin,yunjiao2,sp,colored);
            sentence.push_back(sentence[0]);
            sentence.erase(sentence.begin());
            temp.push_back(sentence);
        }
        poem.push_back(temp);
        //temp.assign(poem.end()-9,poem.end());
    }
    rvaluein.close();
    wordslibin.close();
}

#endif
