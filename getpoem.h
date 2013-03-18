/**
 * @file getpoem.h
 * @brief	初始种群生成
 * @author li shuangjiang
 * @version 1.0.0
 * @date 2012-11-05
 */

#ifndef GTEPOEM_H_
#define GETPOEM_H_
#include "def.h"
#define NOPOEM 500

/**
 * @brief	判断3字句是否符合语法结构
 *
 * @param	sentence	待判定句子
 * @param	fin	wordslib.data二进制输入流
 *
 * @return	判定结果，符合语法为1，不符合语法为0	
 */
int sytax_3(vector<int>& sentence,ifstream& fin)
{
	//三字句两种结构1/2,2/1
	//语法结构有 n+v,n+a,d+v,a+n,v+n
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
//判断4字句是否符合语法结构
/**
 * @brief	判断4字句是否符合语法结构
 *
 * @param	sentence	待判定的句子
 * @param	fin	wordslib.data二进制输入流
 *
 * @return	判定结果，符合语法为1，不符合语法为0	
 */
int sytax_4(vector<int>& sentence,ifstream& fin)
{
	//四字句的结构为2/2
	//结构同3字句,外加n+n结构
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
 * @brief	判断5字句是否符合语法结构
 *
 * @param	sentence	待判定的句子
 * @param	fin	wordslib.data二进制输入流
 *
 * @return	判定结果，符合语法为1，不符合语法为0	
 */
int sytax_5(vector<int>& sentence,ifstream& fin)
{
	//5字句有两种结构2/1/2,2/2/1
	//语法结构为n+n+n,n+n+v,n+n+a,n+v+n,n+v+d,v+n+n
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
 * @brief	判断6字句是否符合语法结构
 *
 * @param	sentence	待判定的句子
 * @param	fin	wordslib.data二进制输入流
 *
 * @return	判定结果，符合语法为1，不符合语法为0	
 */
int sytax_6(vector<int>& sentence,ifstream& fin)
{
	//6字句只有一种结构2/2/2
	//结构同5字句
	return sytax_5(sentence,fin);
}
/**
 * @brief	判断7字句是否符合语法结构
 *
 * @param	sentence	待判定的句子
 * @param	fin	wordslib.data二进制输入流
 *
 * @return	判定结果，符合语法为1，不符合语法为0	
 */
int sytax_7(vector<int>& sentence,ifstream& fin)
{
	//7字句有两种结构2/2/1/2和2/2/2/1
	//结构有 n+n+n+v,n+n+n+a,n+n+d+v,n+n+a+n,n+v+n+n,n+v+n+v,n+a+n+a,a+n+a+n,a+n+d+v,a+n+v+n

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

//语法正确性评价函数，评判句子是否符合语法规则，符合则返回1，不符合返回0
//sentence为待判定的词句,fin为打开二进制文件wordslib.data的流
/**
 * @brief	语法正确性评价函数，评判句子是否符合语法规则，符合则返回1，不符合返回0
 *
 * @param	sentence	待判定的句子
 * @param	fin	wordslib.data二进制文件输入流
 *
 * @return	符合则返回1，不符合返回0
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
 * @brief	句子相关性得分评价函数,两个指标，句子中每个词同主题词之间的相关性之和，以及相邻词之间的相关性之和
 *
 * @param	sentence	待判定的句子组合
 * @param	keyword		主题词ID
 * @param	rvaluein	reva.data文件二进制输入流
 *
 * @return	句子相关性得分
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
 * @brief	句子情感性评价函数，返回各个句子中词语情感值方差的倒数
 *
 * @param	sentence	带评价的句子
 * @param	fin	wordslib.data文件二进制输入流
 *
 * @return	句子情感得分	
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
 * @brief	从候选词词表中按给定平仄韵律模式随机选择词组成词
 *
 * @param	length	要选的词的长度
 * @param	pattern	要选词的平仄韵律模式
 * @param	wordlist	候选词词表
 * @param	sp	指针，指向wordslib.data中不同长度词的id范围
 * @param	fin	wordslib.data文件二进制输入流
 * @param	colored	标记wordslib.data中每个词的颜色，反映该词是否已经选过
 *
 * @return	选中词的id
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
 * @brief	从候选词词表中按给定平仄韵律模式随机选择符合韵脚词组成词
 *
 * @param	length	要选的词的长度
 * @param	pattern	要选词的韵律模式
 * @param	wordlist	候选词词表
 * @param	sp	指针，指向wordslib.data中不同长度词的id范围
 * @param	fin	wordslib.data文件二进制输入流
 * @param	colored	标记wordslib.data中每个词的颜色，反映该词是否已经选过
 * @param	yunjiao	待选词的韵脚ID
 *
 * @return	选中词的id
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
 * @brief	获取与给定关键词相关性大于k的一级和二级词表，至少包含max个，采用了类似于BFS的搜索方法
 *
 * @param	k	相关度阈值
 * @param	max	待选词的数量
 * @param	length	待选词的长度
 * @param	wordlist	返回的待选词词表
 * @param	colored	标记wordslib.data中的词语是否已经被选择过
 * @param	fin	reva.data文件的二进制输入流
 *
 * @return	选词是否成功
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
                        //判断编号为j的词是否已经在list里,不在则加入list
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
 * @brief	在候选词词表中选出符合韵脚的词语组成韵脚表
 *
 * @param	wordlist	候选词词表
 * @param	yjlist	选中的词构成的韵脚表
 * @param	fin	wordslib.data的输入流
 * @param	length	要选择词的词长
 * @param	yunjiao	要选则词满足的韵脚ID
 * @param	sp	wordslib.data中各不同词长的id范围
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
 * @brief	根据词表中的词和给定的韵律模式以及韵脚随机组合出句子
 *
 * @param	pattern	要生成句子的平仄格律模式
 * @param	sentence	返回的句子
 * @param	wordlist	候选词词表
 * @param	fin	wordslib.data数据输入流
 * @param	yunjiao	要生成句子的韵脚
 * @param	sp	wordslib.data中各不同词长的id范围
 * @param	colored	标记用过的词
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
 * @brief	填充句子的韵脚部分
 *
 * @param	length	韵脚词的长度
 * @param	pattern	要填充韵脚词的平仄格律模式
 * @param	wordlist	候选词词表
 * @param	sentence	返回的韵脚填好的句子
 * @param	yjlist	候选韵脚词列表
 * @param	fin	wordslib.data数据输入流
 * @param	colored	标记用过的词
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
 * @brief	根据给定的词牌，关键词，候选词词表随机组合出满足格律和韵脚的词	
 *
 * @param	cipai	给定的词牌ID
 * @param	keyword	给定的关键词ID
 * @param	wordlist	候选词词表
 * @param	poem	返回的生成的宋词
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

    //构建候选词表
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
