//////////////////////////////////////////////////////

// //Checks if path is valid and simultaneously adds position to a result vector
// bool getPath(int** matrix, int currRow, int currColumn, vector<Point*>& path, unordered_set<Point*>& duplicateVisits){
    
//     //if out of bounds or curr position is off limits, return false
//     if (currRow < 0 || currColumn < 0 || matrix[currRow][currColumn] == -1){
//         return false;
//     }
    
//     Point* currPos = new Point(currRow, currColumn);
    
//     //If we have already visited this position, then return false
//     if (duplicateVisits.find(currPos) != duplicateVisits.end()){
//         return false;
//     }
    
    
//     bool atOrigin = currRow == 0 && currColumn == 0;
    
//     //Everytime robot moves up or left and it is a valid position, add the point to result vector
//     if (atOrigin || getPath(matrix, currRow-1, currColumn, path, duplicateVisits) || getPath(matrix, currRow, currColumn-1, path, duplicateVisits)){
//         path.push_back(currPos);
//         return true;
//     }
    
//     //Keep track of already visited points
//     duplicateVisits.insert(currPos);
    
//     return false;
// }

// vector<Point*> getPath(int** matrix, int rows, int columns){
//     //create result vector
//     vector<Point*> path;
    
//     //create unordered set to keep track of already visited points
//     unordered_set<Point*> duplicateVisits;
    
//     //Bounds checking
//     if (rows != 0 || matrix != nullptr){
//         //Start checking positions from bottom right to top left
//         if (getPath(matrix, rows - 1, columns - 1, path, duplicateVisits)){
//             return path;
//         }
//     }
//     //Return an empty vector indicating path does not exist
//     return path;
    
// }
