int datevalidate(int dd, int mm, int yy){
   if(yy>=100 && yy<=9999){
      if(mm>=1 && mm<=12){
         if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12));
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11));
               else if((dd>=1 && dd<=28) && (mm==2));
                  else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)));
            else
               return 0;
            } else{
            return 0;
         }
      } else {
      return 0;
   }
}