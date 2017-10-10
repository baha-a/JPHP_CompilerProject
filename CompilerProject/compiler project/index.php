<?php


//////////////////////////////////////// Object class example, the superclass


class OBJ{}
class OBJ2 extends OBJ{}
Object $obj = new OBJ();


class Object2{}

class PRNT{}
class XQ extends PRNT{}
Object $rq = new Object();







///////////////////////////////////// divide by zero run time exeption example

echo "enter number :";
int $t = 7;
double $x = 10.0 / ($t - readInt());

echo $x;








///////////////////////////////////// switch case example

//--------------------------------------------------------------
//         switch case exmple
//--------------------------------------------------------------
 
for(int $t=5; $t<12 ;$t++)
{
 //string  $s="hello2";
  switch($t)
  {
  
      //case  5  : {  echo "5";     break; } 
      case  5  : {  echo "5";     break; } 
      
      case  6  : {  echo "6";     break; } 
      
      case  8  : {  echo "8";     break; }
      //case  8  : {  echo "8";     break; }
      
      //case  9  : {  echo "9";     break; }
      case  9  : {  echo "9";     break; }
       
        
      default  : {  echo  $t;          }
  }
  
  echo "\n";
}
echo "\nPress Enter To Foreach";
readString();
//----------------------------------------------------------------

//----------------------------------------------------------------


//--------------- foreach exmple ---------------------------------


int[] $aa =new int[4] ; 

int $i=0;

while($i<4)
{
    $aa[$i]=1+$i;
    echo  $aa[$i],"\t";
    $i++;    

}



echo "\n";
$aa=new int[4];
int[] $aa2=new int[4];


$i=0;

while($i<4)
    $aa[$i] = ++$i;
$i = 0;
while($i<4)
    $aa2[$i] = ++$i;

foreach(int $a as $aa)
   echo  $a ,"\t";





//----------------------------------------------------------------



// pass int to dounle paramter


string $strswitch = "bbb";
switch($strswitch)
{
case "bca": echo "y";break;
case "bbb": echo "x";break;
//case "bbb": echo "x";break;
}



double $T = (int) ( 5 +  5.5 ); //echo $T;
echo $T;






///////////////////////////////////////////////////// not all paths return value example



function fp() : int
{
      echo "";
      {
        {
            {
                  
            }
              
            if(false)
              return 5;
            else if(false)
                return 34;
            else 
            {              
              if(false)
                  return 3;
              else
                  while(false)
                      return 3;
            }
              
        }
      }
       
      return 0;
}











//////////////////////////////////////////////////////////////// polymorephism example 2

{

abstract class X
{
  public int $t = 9;
  public abstract function fp();
}


class Y extends X
{
  public int $e = 3;
 
  public function fp() 
  {
     echo $e;
  }
}


class Z extends X
{
  public int $e = 4;
  
  public function fp()
  {
      echo $e;
  }
}


X $y = new Z(); 
$y->fp();

$y = new Y();
$y->fp();


Y $q = (Y) (X) new Z();
$q->fp();


}


////////////////////////////////////////////////////////////////////// const variables example
{

        const int $r = 5;
        // $r = 4544;
        echo $r;

        class s
        {
        public static int $i=9;
        public function ff()
        {
        $i++;
        echo $r1;
        echo $i;
        }

        public static const int $r1 = 9;
        }

        echo " - ",s::$r1, "- ";
        ++s::$i;
        s $ss=new s();
        $ss->ff();

}






/////////////////////////////////////////////// floating point variables example 1


{
          cccc[] $aa = new cccc[10];
          $aa[3] = new cccc();

          echo $aa[3]->$d;


          class cccc
          {
              public double $d = 3.5;
              public static double $d2 = 8.5;
    
              public string $d3 = "helloo";
              public static string $d4 = " world\n";
    
              public function flo(double $t = 2.1,string $r="xxxx")
              {
                  echo "\n flo: " , $t ," - " , $d," - " , $d2," - " , $d3 , "\n"; 
                  $t = $d * $t;
                  echo "\n flo: " , $t , "\n";   // $t + " - " yieled error
        
                  echo $r;
              }
    
              public function multTen(double & $t):double
              {
                  $t *= 10;
                  return $t;
              }   
          }

          double $a = -8.1;
          cccc $c = new  cccc();

          echo $a , " - " , $c->$d , " - " , cccc::$d2;

          $c->flo();

          echo $a , " - " , $c->$d , " - " ,cccc::$d2;

          echo "\n", $c->$d3 , cccc::$d4;

          echo "\n-------------\n";

          echo $a," - ", $c->multTen($a) , " - " , $a ,"\n";
}


echo "press enter to continue . . .";
readString();


if(0)
  ;
else
  echo "tyyruru\n";

//////////////////////////////////////////////////////////////////////////////////// inner class example

class Out
{
    class inr { public function C(){echo "\n" + "it's working..." + "\n";}}
    static class inr2 { public function fo(){echo "ha";} }
    public static function foo(){}
    
    public static int $Q;
}

class test
{
    public static function f()
    {
        Out::$Q = 9944;
        echo Out::$Q;

        Out $tx = new Out();
        Out::inr2 $tw = new Out::inr2();
        $tw->fo();
        
        
        Out::inr $ty =    $tx => new inr();
        
        $ty->C();
    }
}

test::f();


//////////////////////////////////////////////////////////////////////////////////// string + string

echo "enter string:"; 

string $strPluss = (45 + 5 + " dfdfdf " + 1 + 1 + 1 + readString() + (1 + 1) + "kjjjj" + 993);

echo $strPluss +"\n";



//////////////////////////////////////////////////////////////////////// floating point numbers example 2


function FF(double $t)
{
echo "enter double number:";
double $d3 = 0.10;
double $d1 = 6.756;
double $d2 = $t;
double $d4 = readDouble();

echo $d1," - ", $d2," - ", $d3," - ", $d4,"\n";
$d1 += $d4;
echo $d1," - ", $d2," - ", $d3," - ", $d4,"\n";

}


FF(6.2);
FF(2.2);
FF(1.1);
FF(2222.2);















//////////////////////////////////////////////////////////////////// array of class    example 
//////////////////////////////////////////////////////////////////// and implicit casting

{
Qq[] $g = new Qq[4];

echo $g[0] , "\n";
$g[0] = new R();
echo $g[0] , "\n";

echo $g[0]->$t ," - ";
$g[0]->$t = 9;
echo $g[0]->$t ,"\n";


echo $g[1] , "\n";
$g[1] = new Qq();
echo $g[1] , "\n";

echo $g[1]->$t ," - ";
$g[1]->$t = 1;
echo $g[1]->$t ," - ";
echo $g[0]->$t ,"\n";



class R extends Qq
{

}
class Qq extends Q
{
  public int $t = -5;
}
class Q extends W { }
class W extends E{ public W $t;}
class E{}


}





////////////////////////////////// passing paramters by reference example //////////////////////////////

RFclass $ttt = new RFclass(4);

echo $ttt->$t, " - " ;
RF3($ttt);
echo $ttt->$t,"\n";


int $ref = 3;
echo $ref,"\n";

RF($ref);

echo $ref,"\n";


int[] $refarray=new int[]{1,2,3,4};
echo $refarray[0]," - ",$refarray[1],"\n";
RF2($refarray);
echo $refarray[0]," - ",$refarray[1],"\n";

function RF(int & $r)
{
    $r += 10;
}

function RF2(int[] & $r)
{
    $r = new int[]{5,6,7,8};
}

function RF3(RFclass & $r)
{
    $r = new RFclass();
}


class RFclass
{
      public function RFclass(int $tt = -9999)
      {
          $t = $tt; 
      }
      public int $t = -20;
}




//////////////////////////////////////////////////// polymorphism test example  /////////////////////////////////


abstract class CX
{
      public abstract function foo();
      public function fooBase() { echo "father\n";}
}

class C1 extends CX 
{
    public function foo() { echo "1\n"; } 
    public function fooC1() { echo "Son C1\n";}
}
class C2 extends CX 
{
    public function foo() { echo "2\n"; } 
    public function fooC2() { echo "Son C2\n";}
}

CX $cx2 = new C2();
CX $cx1 = new C1();

$cx1->foo();
$cx2->foo();

CX $tmpCx = $cx1;
$cx1 = $cx2;
$cx2 = $tmpCx;

$cx1->foo();
$cx2->foo();

$cx1->fooBase();
$cx2->fooBase();

C1 $c11 = (C1)$cx1;
$c11->fooC1();

C2 $c22 = (C2)$cx1;
$c22->fooC2();



FX($cx1);
FX($cx2);

function FX(CX $x)  // this is polymorphism
{
    $x->foo();
}




/////////////////////////////////////////////////////////////////////////

class Q1
{
    public int $t;
    public bool $t2 = 8;
    static public int[] $q;
    
}

Q1 $qx = new Q1();
Q1::$q = new int[3];

if(Q1::$q == null) 
  echo "it's null\n";
else 
  echo "it's not null\n";

if($qx->$t == null)
  echo "it's null\n";
else 
  echo "it's not null\n";

echo $qx->$t;echo $qx->$t2;



int[] $qt = null;

if($qt == null)
  echo "it's null";
else 
  echo "it's not null";


$qt = new int[10];
ReadArray($qt,4);
EchoArray($qt,10);

function EchoArray(int[] $e,int $max)
{
echo "the Array elements are :\n";
  for(int $t =0;$t<$max;$t++)
  {
      echo $e[$t];
      
      if($t + 1 < $max)
        echo " - ";
  }
  echo "\n";
}
function ReadArray(int[] $e,int $max)
{
    echo "Enter the array elements:\n";
    for(int $t =0;$t<$max;$t++)
    {
          echo "a[",$t,"]  = ";
          $e[$t] = readInt();
    }
}


if(!(0||0||0||0||1))
  echo "yes1\n";
  
if(!(0||0||0||0||1||0))
  echo "yes2\n";
  
if(!(0||0||0||0||0))
  echo "no1\n";
  
if(!(1 && 1 && 55 && 7 && 1))
  echo "yes4\n\n";
  
if(!(1 && 1 && 55 && 0 && 1))
  echo "no\n";

if(!(0 && 1 && 55 && 8 && 1))
  echo "no\n";

if(!(1 && 55 && 8 && 1 && 0))
  echo "no\n";
  

int $i2 = 1;

if( 9==9 && $i2++)
;
echo $i2;

if( 9==8 && $i2++)
;
echo $i2;


if( 9==9 || $i2++)
;
echo $i2;


if( 8==9 || $i2++)
;
echo $i2;







if(!(9==4))
{
    echo "YES";
}
else {
echo "try again";
}

if(!(9==9))
{
    echo "no";
}
else 
{
echo "yes";
}


function opt(int $i , int $t , int $w , int $q , int $a = 7, int $b=8, int $h = 9)
{
    echo $i," - ",$t," - ",$w," - ",$q," - ",$a," - ",$b," - ",$h,"\n";
}


opt(6,7,8,9,1,2,3);

opt(60,70,80,90,10);

opt(600,700,800,900);





class X
{
    public function X()
    {
        echo "X";
    }
}

class Y extends X
{
    //public function Y()
    //{
        //echo "Y";
    //}
}

class W extends Y
{
    public function W()
    {
        // try to use 'super' keyword here, it will work fine
        echo "W";
    }
}


class Z extends W
{
    public function Z()
    {
        echo "Z";
    }
}

Z $z= new Z();



echo "\n\n";

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

function f1(int $t):int
{
    echo $t, " - ";
    int $i = 8 + $t;
    return $i;
}
function f2(int $t):int
{
    echo $t, " - ";
    return f1($t * 10);
}
function f3(int $t):int
{
    echo $t, " - ";
    return f2($t * 10);
}
function f4(int $t):int
{

    echo $t, " - ";
    return f3($t * 10);
}

function f5(int $t)
{
    echo $t, " - ";
    $t = 9;
    echo $t, " - ";
}



echo f4(5) , "---\n";




int $r = 8;
echo $r , " - ";
f5($r);
echo $r,"\n\n--------------------------\n";




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



class QP
{
    public int $i2;
    public int $i3;
    public int $i4;
    public int $i11;

public function QP()
{
 echo "P";
}
    
    public function I2() : int
    {
        return $i3;
    }
    public function QW(int $x)
    {
        $i11 = $x;
        
        echo $i11,"  ---- \n";
    }
    public function I1() : int
    {
        for(int $i=0;$i<10;$i++)
        {
              echo I2()," - ";
        }
        return I2();
    }
    public function I() : int
    {
        echo $i11,"-XX-- "  ;
        return I1();
    }
    
}

class Q extends QP
{
    int $u;
    int $i;    
    int $t;
   
   public function v()
   {
        echo $u," - ",$t," - ", $i11 ," - ",$i ," - ",$i2," - ",$i3," - ",$i4,"\n";
   }
   public function init()
   {
        $t =999;
        $u = 94;
        $i  = 14;
        $i2 = 13;
        $i3 = 12;
        $i4 = 11;
        $i11 = 3333;
   }
   public function Q()
   {
        echo "Q";
   }
   
   public function QQQ() : int
   {
      return I();
   }
}


Q $q = new Q();

$q->v();
$q->init();
$q->v();

$q->QW(77);

$q->v();

echo $q->QQQ(),"\n ...... ",$q->$i11,"\n";
$q->v();
$q->v();



echo "\n\n";


//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


echo "\n\n";


Array $g = new Array();
$g->ArrayQ(12);


$g->$array[7] = 10;
$g->$array[2] = 102;
$g->$array[6] = 21;

$g->Print();
Array::$a1 = $g;
echo "Max is ", Array::getMax() , "\n";
$g->$array[6] = 555;
$g->$array[6] = 55;
$g->Print();
echo "Max is ", Array::getMax2($g),"\n";

$g->$array = new int[]{ 7 , 4 ,5 , 99 , 10 , 5 , 0 , 1};
$g->Print();
echo "Max is ", Array::getMax2($g),"\n";;


class Array
{
   public int[] $array;
   public int $length;
   
   public function ArrayQ(int $n)
   {
        $length = $n;
        $array = new int[$n];
   }
   public function Print()
   {
        for(int $i = 0; $i< $length ; $i++)
        {
            echo $array[$i];
            
            if($i + 1 != $length)
                echo " - ";
            else
                echo "\n";
        }
   }
   
   public static Array $a1;
   public static function getMax() : int
   {
   
        int $m = $a1->$array[7770];
        
        for(int $i = 1;$i< $a1->$length ;$i++)
        {
          if($m < $a1->$array[$i])
              $m  = $a1->$array[$i];
        }
        return $m;
   }
   
   public static function getMax2(Array $a1) : int
   {
        int $m = $a1->$array[7770];  
        
        for(int $i = 1;$i< $a1->$length ;$i++)
        {
          if($m < $a1->$array[$i])
              $m  = $a1->$array[$i];
        }
        return $m;
   }
}


/////////////////////////////////////////////////////////////////////////////////////////////// super with argument example


int $conut = 0;

class C extends Ctor
{
  public function C(){ super(4); $conut++;}
}

class Ctor
{
    public function Ctor(int $t)
    {
        echo $t," - ";
        $conut++;
    }
}

C $c2 = new C();
echo $conut;



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////// Composition Example

class Point
{
    public int $x;
    public int $y;
    
    public function E()
    {
        echo "POINT :", $x," - ",$y,"\n";
    }
}

class Circle
{
  public Point $center;
  public int $R;
  public function Circle()
  {
    $center = new Point();
  }
  
  public function E()
  {
        echo "Circle : R", $R," - ";
        $center->E();
  }
  
  public function Rsquer() :int 
  {
      return $R * $R;
  }
}

Circle $c= new Circle();
$c->$R=49;
$c->$center = new Point();
$c->$center->$x = 3;
$c->$center->$y = 32;
$c->E();
echo $c->Rsquer();


/////////////////////////////////////////////////////////////////////////////////

?>