#pragma once
#include <vector>
#include <array>
#include <iostream>

template<typename T>
bool CheckCovMat(const std::vector<T> &matrix, bool silent_mode = true) {
    size_t l = matrix.size();
    float n = (-1 + sqrt(1+8*l))/2;
    if (n != floor(n)){
        if (!silent_mode)
            std::cout << "Warning! Covariance matrix has invalid format. Its length L = " << l << ", hence it cannot be interpreted as a square matrix. A square simmetrical NxN matrix must be converted into vector with the length L=(N+1)*N/2.\n";
        return false;
    }

    bool res_flag = true;

    size_t n_int = (size_t)n;
    for (size_t i = 0; i < n_int; i++){
        size_t diag_el_num = (i+1)*i/2 + i;
        if(matrix.at(diag_el_num)<0){
            if (!silent_mode)
                std::cout << "Warning! Covariance matrix has negative diagonal element #" << diag_el_num << " with the value " << matrix.at(diag_el_num) << ". Please, check the matrix.\n";
            res_flag = false;
        }
    } 
    
    for (size_t i = 0; i < n_int; i++){
        for (size_t j = 0; j < i; j++){
            size_t ij = i*(i+1)/2 + j;
            size_t ii = i*(i+1)/2 + i;
            size_t jj = j*(j+1)/2 + j;
            float c_ij = matrix.at(ij);
            float c_ii = matrix.at(ii);
            float c_jj = matrix.at(jj);
            if (abs(c_ij) > sqrt(c_ii*c_jj)){
                if (!silent_mode)
                    std::cout << "Warning! Covariance matrix has non-diagonal element C" << ij << " = " << c_ij << " does not satisfy the condition abs(Cij) < sqrt(Cii*Cjj) (C"<< ii << " = " << c_ii << ", C" << jj << " = " << c_jj << "). Please, check the matrix.\n";
                res_flag = false;
            }
        }
    }

    if (res_flag){
        if (!silent_mode)
            std::cout << "Covariance matrix is OK!\n";
    }
    return res_flag;
}

template<typename T, int l>
bool CheckCovMat(const std::array<T,l> &matrix, bool silent_mode = true) {
    float n = (-1 + sqrt(1+8*l))/2;
    if (n != floor(n)){
        if (!silent_mode)
            std::cout << "Warning! Covariance matrix has invalid format. Its length L = " << l << ", hence it cannot be interpreted as a square matrix. A square simmetrical NxN matrix must be converted into vector with the length L=(N+1)*N/2.\n";
        return false;
    }

    bool res_flag = true;

    size_t n_int = (size_t)n;
    for (size_t i = 0; i < n_int; i++){
        size_t diag_el_num = (i+1)*i/2 + i;
        if(matrix.at(diag_el_num)<0){
            if (!silent_mode)
                std::cout << "Warning! Covariance matrix has negative diagonal element #" << diag_el_num << " with the value " << matrix.at(diag_el_num) << ". Please, check the matrix.\n";
            res_flag = false;
        }
    } 
    
    for (size_t i = 0; i < n_int; i++){
        for (size_t j = 0; j < i; j++){
            size_t ij = i*(i+1)/2 + j;
            size_t ii = i*(i+1)/2 + i;
            size_t jj = j*(j+1)/2 + j;
            float c_ij = matrix.at(ij);
            float c_ii = matrix.at(ii);
            float c_jj = matrix.at(jj);
            if (abs(c_ij) > sqrt(c_ii*c_jj)){
                if (!silent_mode)
                    std::cout << "Warning! Covariance matrix has non-diagonal element C" << ij << " = " << c_ij << " does not satisfy the condition abs(Cij) < sqrt(Cii*Cjj) (C"<< ii << " = " << c_ii << ", C" << jj << " = " << c_jj << "). Please, check the matrix.\n";
                res_flag = false;
            }
        }
    }

    if (res_flag){
        if (!silent_mode)
            std::cout << "Covariance matrix is OK!\n";
    }
    return res_flag;
}

template<typename T, int l>
bool CheckCovMat(const T (&matrix)[l], bool silent_mode = true) {
    float n = (-1 + sqrt(1+8*l))/2;
    if (n != floor(n)){
        if (!silent_mode)
            std::cout << "Warning! Covariance matrix has invalid format. Its length L = " << l << ", hence it cannot be interpreted as a square matrix. A square simmetrical NxN matrix must be converted into vector with the length L=(N+1)*N/2.\n";
        return false;
    }

    bool res_flag = true;

    size_t n_int = (size_t)n;
    for (size_t i = 0; i < n_int; i++){
        size_t diag_el_num = (i+1)*i/2 + i;
        if(matrix[diag_el_num]<0){
            if (!silent_mode)
                std::cout << "Warning! Covariance matrix has negative diagonal element #" << diag_el_num << " with the value " << matrix[diag_el_num] << ". Please, check the matrix.\n";
            res_flag = false;
        }
    } 
    
    for (size_t i = 0; i < n_int; i++){
        for (size_t j = 0; j < i; j++){
            size_t ij = i*(i+1)/2 + j;
            size_t ii = i*(i+1)/2 + i;
            size_t jj = j*(j+1)/2 + j;
            float c_ij = matrix[ij];
            float c_ii = matrix[ii];
            float c_jj = matrix[jj];
            if (abs(c_ij) > sqrt(c_ii*c_jj)){
                if (!silent_mode)
                    std::cout << "Warning! Covariance matrix has non-diagonal element C" << ij << " = " << c_ij << " does not satisfy the condition abs(Cij) < sqrt(Cii*Cjj) (C"<< ii << " = " << c_ii << ", C" << jj << " = " << c_jj << "). Please, check the matrix.\n";
                res_flag = false;
            }
        }
    }

    if (res_flag){
        if (!silent_mode)
            std::cout << "Covariance matrix is OK!\n";
    }
    return res_flag;
}