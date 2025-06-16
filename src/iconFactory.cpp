// TODO implementation
//
//
//
#include "iconFactory.h"




Icon IconFactory::createIcon(Color color, const std::string& ascii) {
    std::vector<std::vector<Cell>> cells;
    std::vector<Cell> currentRow;
    
    
    for (size_t i = 0; i < ascii.length(); ++i) {
        char c = ascii[i];
        
        if (c == '\n') {
            
            if (!currentRow.empty()) {
                cells.push_back(currentRow);
                currentRow.clear();
            }
        } else {
           
            currentRow.push_back(Cell(color, std::string(1, c)));
        }
    }
    
 
    if (!currentRow.empty()) {
        cells.push_back(currentRow);
    }
    
    
    if (cells.empty()) {
        cells.push_back(std::vector<Cell>());
    }
    
    return cells;
}
