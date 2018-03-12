#include "Particles.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#include <eigen3/Eigen/Dense>

using namespace std;
using namespace Eigen;

inline sqr(double x){
    return x * x;
}

Particle::Particle(double &w, VectorXf &xv, MatrixXf &Pv, vector<VectorXf> &xf, vector<MatrixXf> &Pf, double *da){
    _w = w;
    _xv = xv;
    _Pv = Pv;
    _xf = xf;
    _Pf = Pf;
    _da = da;
}

Particle::~Particle(){}

double& Particle::w(){
    return _w;
}

VectorXf& Particle::xv(){
    return _xv;
}

MatrixXf& Particle::Pv(){
    return _Pv;
}

vector<VectorXf>& Particle::xf(){
    return _xf;
}

vector<MatrixXf>& Particle::Pf(){
    return _Pf;
}

double* Particle::da(){
    return _da;
}

void Particle::setW(double w){
    _w = w;
}

void Particle::setXv(VectorXf& xv){
    _xv = xv;
}

void Particle::setPv(MatrixXf& Pv){
    _Pv = Pv;
}

void Particle::setXf(vector<VectorXf>& xf){
    _xf = xf;
}

void Particle::setXfi(unsigned long i, VectorXf& vec){
    if (i >= _xf.size()) _xf.resize(i + 1);
    _xf[i] = vec;
}

void Particle::setPf(vector<MatrixXf>& Pf){
    _Pf = Pf;
}

void Particle::setPfi(unsigned long i, MatrixXf& M){
    if (i >= _Pf.size()) _Pf.resize(i + 1);
    _Pf[i] = M;
}

void Particle::setDa(double * da){
    _da = da;
}
