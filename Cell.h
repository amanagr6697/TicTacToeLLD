#ifndef CELL_H
#define CELL_H


class Cell{
 
  private:
  int ceLlValue;
  public:
  Cell(): ceLlValue(0){}

  int getCellValue(){
    return ceLlValue;
  }

  void setCellValue(int value){
    ceLlValue = value;
  }
};







#endif