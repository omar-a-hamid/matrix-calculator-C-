#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;



int const sizr = 100;
int const sizc = 100;
float a[sizr][sizc];// { {1 ,2 ,3} ,{3, 2, 1} ,{2,3, 1} };
float b[sizr][sizc];
float c[sizr][sizc];
float i[sizr][sizc];
float tb[sizr][sizc];
//float e[sizr][sizc];
                                                                    //less than a days work left 
string t;
string sa;
string sb;
string aorb;                                //classing 
int printr;
float b0, i0;
int printc;
int printrb;
int printcb;                            // consider classing
int printrc;
int printcc;
float num;
int row;
int colmn;
int detv;

int dashboard();
void adde();
void subs();
void mult();            //consider classing the operations 
void div();
void trans();
void retb();

//testing
void det();

void inverse();

void id();
void strb();

class printer {
public:
    void pa() {
        cout << "matrix A = " << endl << "[";
        for (int y = 0; y <= printr; y++) {
            for (int x = 0; x <= printc; x++) {

                cout << a[y][x];// << " ";

                if (x < printc) { cout << " "; }
                else if (x == printc && y < printr) { cout << "; "; }


            }
            //  cout << endl;
        }
        cout << "]" << endl;
    }

    void pb() {
        cout << "matrix B = " << endl << "[";

        for (int y = 0; y <= printrb; y++) {
            for (int x = 0; x <= printcb; x++) {

                cout << b[y][x]; //  << " ";
                if (x < printcb) { cout << " "; }
                else if (x == printcb && y < printrb) { cout << "; "; }




            }
            //cout << endl;
        }
        cout << "]" << endl;
    }
    void pc() {
        cout << "matrix C = " << endl << "[";

        for (int y = 0; y <= printrc; y++) {

            for (int x = 0; x <= printcc; x++) {

                cout << c[y][x];                                        //!! changed t o  i fpr testing                                              
                if (x < printcc) { cout << " "; }
                else if (x == printcc && y < printrc) { cout << "; "; }






            }
            //cout << endl;

        }
        cout << "]" << endl;
    }


};
class defi {
public:


    void fetch(string aorb2) {

        if (aorb2 == "a") {

            cout << "input matrix A " << endl;

            do {
                getline(cin, sa);

            } while (sa.length() == 0);
            if (sa == "exit") { exit(0); }

            da(sa);


        }
        else if (aorb2 == "b") {
            cout << "input matrix B " << endl;
            do {
                getline(cin, sb);
            } while (sb.length() == 0);
            if (sb == "exit") { exit(0); }
            db(sb);
        }

        else if (aorb2 == "exit") { exit(0); }


        else {
            cout << "ERROR! " << endl;


        }


    }

    void da(string s) {


        s.erase(0, 1);

        for (row = 0; row < sizr; row++) {
            for (colmn = 0; colmn < sizc; colmn++) {

                string numb = s.substr(0, s.find(" "));
                num = stof(numb);
                a[row][colmn] = num;

                if (s.find(" ") > s.find(";")) {
                    printc = colmn;
                    colmn = sizc + 1;

                }
                s.erase(0, s.find(" ") + 1);

            }
            if (s.find(" ") > s.find("]")) {
                printr = row;
                row = sizr + 1;
            }
        }
    }


    void db(string p) {

        p.erase(0, 1);

        for (row = 0; row < sizr; row++) {
            for (colmn = 0; colmn < sizc; colmn++) {

                string numb = p.substr(0, p.find(" "));
                num = stof(numb);
                b[row][colmn] = num;

                if (p.find(" ") > p.find(";")) {
                    printcb = colmn;
                    colmn = sizc + 1;

                }
                p.erase(0, p.find(" ") + 1);
            }
            if (p.find(" ") > p.find("]")) {
                printrb = row;
                row = sizr + 1;
            }




        }




    }
};

printer print;
defi def;

//[1.2 2.2 3.1; -4.5 5.4 6.3; 2.3 5.2 4.7]
//[2.2 4.2 2.1; -4.5 3.4 5.3; 1.2 4.7 4.5]

//[1 2 3; -4 5 6; 2 5 4]
//[2 4 2; -4 3 5; 1 4 5]
//[2 4 2 -4 3; -4 3 5 5 4; 1 4 5 6 8; -4 3 5 5 4; 1 4 5 6 8; -4 3 5 5 4; 1 4 5 6 8; -4 3 5 5 4; 1 4 5 6 8; -4 3 5 5 4; 1 4 5 6 8; -4 3 5 5 4; 1 4 5 6 8; -4 3 5 5 4; 1 4 5 6 8]
//[2.2 4.2 2.1; -4.5 3.4 5.3; -4.5 3.4 5.3; -4.5 3.4 5.3; -4.5 3.4 5.3; -4.5 3.4 5.3; -4.5 3.4 5.3; -4.5 3.4 5.3; -4.5 3.4 5.3; -4.5 3.4 5.3; -4.5 3.4 5.3; -4.5 3.4 5.3; 1.2 4.7 4.5]
//[1 1 1; 1 1 1; 1 1 1]
//[1 1 1; 1 1 1; 1 1 1]
//[1 2 1; 2 1 1; 1 1 2]
//[1 1; 1 1; 1 1]
//[]

int main()
{
    def.fetch("a");

    def.fetch("b");



    dashboard();
}

int dashboard() {
    string show;

    cout << "1.show matrix " << endl;
    cout << "2.addition " << endl;
    cout << "3.substraction " << endl;
    cout << "4.multiplication " << endl;
    cout << "5.transpose " << endl;
    cout << "6.divide " << endl;
    cout << "7.define " << endl;
    cin >> t;
    if (t == "1") {
        cout << "choose A or B or C or else to return" << endl;
        cin >> show;
        if (show == "a") { print.pa(); }
        if (show == "b") { print.pb(); }
        if (show == "c") { print.pc(); }
        else { dashboard(); }
    }
    else if (t == "2") {
        adde();

        dashboard();
    }


    else if (t == "3") {
        subs();

    }
    else if (t == "4") {
        mult();

    }
    else if (t == "5") {
        trans();

    }
    else if (t == "6") { div(); }
    else if (t == "7") {                                    //

        cout << "choose 'a' or 'b' " << endl;
        //cin >> aorb;
        cin >> aorb; //test if makes it stop

        //getline(cin, aorb);

        def.fetch(aorb);


    }
    if (t == "exit") { return 0; }

    else { dashboard(); }
}


void adde() {
    if (printr == printrb && printc == printcb) {
        for (int q = 0; q <= printr; q++) {
            for (int w = 0; w <= printc; w++) {
                printrc = printr;
                printcc = printc;
                c[q][w] = a[q][w] + b[q][w];



            }


        }
        print.pc();
    }

    else {
        cout << "ERROR!" << endl;
    }
}
void subs() {

    if (printr == printrb && printc == printcb) {
        for (int q = 0; q <= printr; q++) {
            for (int w = 0; w <= printc; w++) {
                printrc = printr;
                printcc = printc;
                c[q][w] = a[q][w] - b[q][w];



            }


        }
        print.pc();
    }

    else {
        cout << "ERROR!" << endl;
    }


}
void mult() {
    //cout << "AXB OR BXA" << endl;
    int sum = 0;

    //string h;
    //cin >> h;
    printrc = printr;
    printcc = printcb;
    for (int x = 0; x <= printr; x++) {
        for (int p{}; p <= printcc; p++) {
            c[x][p] = 0;
        }
    }
    // if (h == "axb") {
    if (printc == printrb) {
        for (int y = 0; y <= printcb; y++) { // c[y][x] = a[y][z] X b[z][x] 
                         //printcb
            for (int x = 0; x <= printr; x++) {
                //printr

                for (int z = 0; z <= printc; z++) {
                    c[x][y] += a[x][z] * b[z][y];





                }



            }                                                         //multiply func.
        }
        print.pc();
    }
    else { cout << "ERROR!" << endl; }
    //}
  //  else if (h == "bxa"){
    //}
}                                                        //empty
void div() {

    strb();
    det();
    retb();

    if (detv == 0) {
        cout << "ERROR!" << endl;
    }

    else {   //check is inversable and if after inverse are multiplyable 
        //chek if determinant =0 
        //det(); 
        // check if  square matrix
        // if printrb == printrcb
        // d[][] = b [][]   no.1 
        // inverse d[][] 
        // b [][] = d [][] inverse  // reverse no.1
        // mult(); // needs editing to enter on axb dirctly 
        if (printrb == printcb) {
            id();
            inverse();

            mult();
            retb();



        }
        //find a systmatic way of inversion 
            //if you willl choose minor co factors than devidde matrcies to smaller matrcies add a matrix to calc every matrix
            //than assign the number to the inverse matrix then move to next mattrix to be creted
            //size of matrix let e[][] is printre =printce = printcb - 1 = printrb -1

            //if you will use the row operations than chech for zeros in diagonals
            //swap rows to get no zeros in diagonals 
            //take the diagonal a common factor than mult by the pther rows then substract the numbers 


        /*for (int x = 0; x <= printrb; x++) {  //make e[][] identy matrix
            e[x][x] = 1; // zero others
        }*/
    }
}
void trans() {
    printcc = printr;
    printrc = printc;
    for (int r = 0; r <= printr; r++) {
        for (int co = 0; co <= printc; co++) {


            c[co][r] = a[r][co];







        }
    }

    print.pc();
}

void det() {
    //to calculate determinnat value of matrix e[][] 
        //same as inversio nbut instead of fully lapping lap from where you stand in the row and go down from there 
    int ns = 0;
    for (int z = 0; z <= printrb; z++) {//#2 checks all diagonal members for zeros
        while (b[z][z] == 0) {//#3
            for (int y = 0; y <= printrb; y++) {//#4

                if (z == printrb) {//#6 if you are in the last line swap up
                    b0 = b[z][y];
                    b[z][y] = b[z - 1][y];
                    b[z - 1][y] = b0;
                    ns++;
                }//6
                else {//#5
                    b0 = b[z][y]; // if this isnt the last line 
                    b[z][y] = b[z + 1][y];
                    b[z + 1][y] = b0;
                    ns++;

                }//#5
            }//#4
        }//#3
    }//end of for loop to check if diagonal is non zeros # 2


    int o1 = 0;
    float dp = 1;
    float d1 = 1;
    for (int x = 0; x <= printcb; x++) {// #7
        o1 = x;

        float bxx = b[x][x];
        d1 = d1 * bxx; // holds value of divisions
        for (int y = 0; y <= printcb; y++) {//#8

            if (bxx == 0) { break; }
            b[x][y] = b[x][y] / bxx;


        }//#8
        for (int j = 0; j <= printrb; j++) {//9
            float bjo = b[j][o1];


            for (int g = 0; g <= printrb; g++) {//10

                if (j > x) {//11
                    b[j][g] = b[j][g] - b[x][g] * bjo;

                }//11

            }//10


        }//9

        dp = dp * b[x][x];

        detv = d1 * dp;



        //if ns not divisbale by 2 add -ve 

    }//#7

  //  cout << detv << endl; 


}
void inverse() {
    //making inverse matrix

    if (printrb != printcb) {
        cout << "error" << endl;
    }
    // else  if (printrb == printcb) {    //# 1 



 /*        for (int x = 0; x <= printrb; x++) { // to store value of b
             for (int y = 0; y <= printrb; y++) {
                 tb[x][y] = b[x][y];

                 cout << tb[x][y] << " ";
             }
                 cout << endl ;
         }*/

    for (int z = 0; z <= printrb; z++) {//#2 checks all diagonal members for zeros
        while (b[z][z] == 0) {//#3
            for (int y = 0; y <= printrb; y++) {//#4

                if (z == printrb) {//#6 if you are in the last line swap up
                    b0 = b[z][y];
                    b[z][y] = b[z - 1][y];
                    b[z - 1][y] = b0;

                    i0 = i[z][y];
                    i[z][y] = i[z - 1][y];
                    i[z - 1][y] = i0;


                }//6
                else {//#5
                    b0 = b[z][y]; // if this isnt the last line 
                    b[z][y] = b[z + 1][y];
                    b[z + 1][y] = b0;
                    i0 = i[z][y];
                    i[z][y] = i[z + 1][y];
                    i[z + 1][y] = i0;
                }//#5
            }//#4
        }//#3
    }//end of for loop to check if diagonal is non zeros # 2


// -----------------------------------------------------------------------------
//after manging the zeros
//work colmn-> rows
//div col by diagonal 
//for every row(z), rz-rdiagonal

//double for loops one for row(x) one for colmn(y) x++, y++  
//if x==y that elm is diagonal 

    int o = 0;
    float bjo = 0;
    float bxx = 0;



    for (int x = 0; x <= printcb; x++) {// #7
        o = x;
        bxx = b[x][x];
        for (int y = 0; y <= printcb; y++) {//#8


            b[x][y] = b[x][y] / bxx;
            i[x][y] = i[x][y] / bxx;

        }//#8
        for (int j = 0; j <= printrb; j++) {//9
            bjo = b[j][o];

            for (int g = 0; g <= printrb; g++) {//10

                if (j != x) {//11
                    b[j][g] = b[j][g] - b[x][g] * bjo;
                    i[j][g] = i[j][g] - i[x][g] * bjo;


                }//11

            }//10


        }//9



    }//#7
    print.pb();

    for (int x = 0; x <= printrb; x++) {//12
        for (int y = 0; y <= printrb; y++) {//13
            b[x][y] = i[x][y];



        }//13
    }//12
    print.pb();
    //}  // end of if statment to check if B is a square matrix #1

}
void id() {  //identity matrix creator




    for (int x = 0; x <= printrb; x++) {

        for (int y = 0; y <= printrb; y++) {
            i[x][y] = 0;
        }
        i[x][x] = 1;
    }

}
void retb() {
    for (int x = 0; x <= printrb; x++) {
        for (int y = 0; y <= printrb; y++) {
            b[x][y] = tb[x][y];


        }

    }
}
void strb() {
    for (int x = 0; x <= printrb; x++) { // to store value of b
        for (int y = 0; y <= printrb; y++) {
            tb[x][y] = b[x][y];

            // cout << tb[x][y] << " ";
        }
        // cout << endl;
    }
}
