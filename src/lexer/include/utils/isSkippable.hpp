#pragma once

namespace utils {
    bool isSkippable(char token){
        if (token == ' '){ //checks for spaces. 
            return true;       
        }
        return false; 
    }
}