#include <bits/stdc++.h>
#define teamNUM 6

using namespace std;

ifstream ifs;
string opt= "+*";
int row,  col, winTeam;
long long int team[teamNUM]={0};
char **score, ***Map, ***scoreMap, *scoreData;

long long int trans(){
        long long int num=0;
        int len= strlen(Map[row][col])-1;
        while(len)
                num += (Map[row][col][len]-'0')*pow(10,strlen(Map[row][col])-1-len--);
        return num;
}

void record(){
        ofstream ofs;
        ofs.open("score.txt");
        if(!ofs.is_open()){
                cout << "Failed to open file.\n";
                return;
        }

        for(int i=0;i<teamNUM;i++)
                ofs << team[i] << ',';

        ofs.close();
}

void showScore(){
        printf("-----------------------------------------------------\n");
        printf("\n各小隊累計得分：\n");
        for(int i=0;i<teamNUM;i++)
                printf("\t第 %d 小隊：%lld\n", i+1, team[i]);
        printf("\n-----------------------------------------------------\n\n");
}

void showMap(){
        printf("       ");
        for(int i=1;i<11;i++)
                printf("%3d  ", i);
        printf("\n      ┌────┬────┬────┬────┬────┬────┬────┬────┬────┬────┐\n");
        for(int i=1;i<11;i++){
                printf("%4d  │", i);
                for(int j=1;j<11;j++)
                        printf("%4s│", Map[i][j]);
                printf("\n");
                if(i<10)
                        printf("      ├────┼────┼────┼────┼────┼────┼────┼────┼────┼────┤\n");
        }
        printf("      └────┴────┴────┴────┴────┴────┴────┴────┴────┴────┘\n");
}

int main()
{
        score= (char**)malloc(100*sizeof(char*));
        Map= (char***)malloc(11*sizeof(char**));
        scoreMap= (char***)malloc(11*sizeof(char**));
        for(int i=0;i<11;i++){
                Map[i]= (char**)malloc(11*sizeof(char*));
                scoreMap[i]= (char**)malloc(11*sizeof(char*));
        }

        ifs.open("score.txt");
        if(!ifs.is_open()){
                cout << "Failed to load data.\n";
                return 1;
        }
        char scoreData[2000];
        memset(scoreData,'\0',2000*sizeof(char));
        ifs.read(scoreData, 2000);
        ifs.close();

        int i=0, digit=0, teamNum=teamNUM;
        char scoreNum[20];
        memset(scoreNum, 0, 20*sizeof(char));
        for(int i=strlen(scoreData)-1;i>=0;i--){
                if(scoreData[i]==','){
                        teamNum--;
                        digit=0;
                        continue;
                }
                team[teamNum] += (scoreData[i]-'0')*pow(10, digit++);
        }

        for(int i=0;i<100;i++){
                char *tmp;
                tmp= (char*)malloc(5*sizeof(char));
                Map[(i/10)+1][(i%10)+1]= (char*)malloc(sizeof(char));
                memset(tmp,'\0',5*sizeof(char));
                memset(Map[i/10+1][i%10+1],'\0',sizeof(char));

                tmp[0]= opt[i%2];
                if(i<4){                                     // "*0"×4
                        tmp[0]= '*';
                        tmp[1]= '0';
                }
                else if(i<16)                           // "+2"×6  "*2"×6
                        tmp[1]= '2';
                else if(i<36)                           // "+4"×10  "*4"×10
                        tmp[1]= '4';
                else if(i<56)                           // "+6"×10  "*6"×10
                        tmp[1]= '6';
                else if(i<76)                           // "+8"×10  "*8"×10
                        tmp[1]= '8';
                else if(i<86){                          // "+10"×5  "*10"×5
                        tmp[1]= '1';
                        tmp[2]= '0';
                }
                else if(i<94){                          // "+20"×4  "*20"×4
                        tmp[1]= '2';
                        tmp[2]= '0';
                }
                else if(i<98){                          // "+50"×2  "*50"×2
                        tmp[1]= '5';
                        tmp[2]= '0';
                }
                else{                                         // "*100"×2
                        tmp[0]= '*';
                        tmp[1]='1';
                        tmp[2]='0';
                        tmp[3]='0';
                }
                score[i]= tmp;
        }
        random_shuffle(score, score+100);

        for(int i=1;i<11;i++)
                for(int j=1;j<11;j++)
                        scoreMap[i][j]= score[(i-1)*10+(j-1)];

        showMap();
        while(1){
                showScore();

                cout << "第幾小隊答對？";
                while(cin >> winTeam){
                        if(winTeam<7 && winTeam>0)
                                break;
                        cout << "\n第幾小隊答對？";
                }

                cout << "請選擇第幾排第幾列（直排橫列）：";
                while(cin >> col >>row){
                        if((col<11 && col>0) && ( row<11 && row>0)){
                                if(strlen(Map[row][col])>0){
                                        printf("已填過，請重新選擇！\n");
                                        cout << "\n請選擇第幾排第幾列（直排橫列）：";
                                        continue;
                                }
                                break;
                        }
                        cout << "\n請選擇第幾排第幾列（直排橫列）：";
                }

                Map[row][col]= scoreMap[row][col];
                system("cls");
                showMap();
                printf("你踩中的是%4s\n", Map[row][col]);
                if(Map[row][col][0]=='*')
                        team[winTeam-1] *= trans();
                else
                        team[winTeam-1] += trans();
                record();
        }
        return 0;
}
