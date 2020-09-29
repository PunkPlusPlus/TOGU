#include <iostream>
#include <cctype>/*���������� ����������� ����������*/
#include <string>
#include <vector> 
std::vector <std::string> GetWords(std::string str1)
{
    /*
    ��������� ������ �� ������ ��������� ����
    */
    std::string TempWord;
    std::vector <std::string> buffer;
    char delim[2] = " ";
    int pos = 0;
    int TempLen = 0;
    int len = str1.size();
    for (int i = 0; i <= len; i++)
    {
        if (str1[i] == delim[0] || i >= len)
        {
            TempWord = str1.substr(pos, i - pos);
            TempLen = TempWord.length() + 1;
            pos += TempLen;
            buffer.push_back(TempWord);
            TempWord.clear();
        }
    }
    /*
    ���������� ������ ��������� ����
    */
    return buffer;
}
std::string GetMaxWord(std::vector <std::string> words)
{
    /*
    ������� ���������� ���� � ������ �����, ���������� �����, � ������� ���� ������ �����
    */
    std::string TempWord;
    int count = 0;
    int max = 0;
    int it = 0;
    std::vector <int> sums;
    for (auto i = words.begin(); i != words.end(); ++i)
    {
        TempWord = *i;
        for (size_t j = 0; j <= TempWord.length(); ++j)
        {
            if (isdigit(TempWord[j]))
            {
                count++;
            }

        }
        std::cout << "word " << *i << " has " << count << " numbers" << "\n";
        sums.push_back(count);
        if (count >= max)
            max = count;
        count = 0;
    }
    for (auto i = sums.begin(); i != sums.end(); ++i)
    {
        if (*i == max)
        {
            return words[it];
        }
        it++;
    }
    return "";
}

std::string SwichReg(std::string BigWord)
{
    /*
    ������ ������� ���� � ����� � ���������� ����������� ����
    */
    for (size_t i = 0; i <= BigWord.size(); i++)
    {
        if (islower(BigWord[i]))
            BigWord[i] = toupper(BigWord[i]);
        else
            BigWord[i] = tolower(BigWord[i]);
    }
    return BigWord;
}

int main()
{
    std::string str1;
    std::getline(std::cin, str1);//������ � ���������� ������
    std::cout << "Your string: " << str1 << "\n";/* ������� GetWords(), GetMaxWord(), SwichReg() ������� ������� ���� ������� main()*/
    std::vector <std::string> words = GetWords(str1);/*�������� ������������� ������� �� �������*/
    std::string BigWord = GetMaxWord(words);
    std::string NewWord = SwichReg(BigWord);

    //    std::cout << BigWord << "\n";
    std::cout << NewWord << "\n";
    return 0;
}
