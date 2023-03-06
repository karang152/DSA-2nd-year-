//https://www.hackerrank.com/challenges/the-birthday-bar/submissions/code/317526540
int birthday(vector<int> s, int d, int m) {

int iSum = 0;

int iSegments = 0;

     for(int i = 0; i < s.size(); i++)

    {

        iSum = 0;

         for(int j = i; j < m + i; j++)

            iSum += s[j];

            if(iSum == d)

            iSegments++;

    }

    return iSegments;

}
