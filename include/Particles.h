#ifndef __PARTICLES_H__
#define __PARTICLES_H__

#include <iostream>
#include <vector>
#include <string>

#include <eigen3/Eigen/Dense>

using namespace std;
using namespace Eigen;

class Particle{
    double _w;
    VectorXf _xv;
    MatrixXf _Pv;
    vector<VectorXf> _xf;
    vector<MatrixXf> _Pf;
    double * _da;

public:
    Particle();
    Particle(double &w, VectorXf &xv, MatrixXf &Pv, vector<VectorXf> &xf, vector<MatrixXf> &Pf, double *da);
    ~Particle();

    double &w();
    VectorXf &xv();
    MatrixXf &Pv();
    vector<VectorXf> &xf();
    vector<MatrixXf> &Pf();
    float *da();

    void setW(double w);
    void setXv(VectorXf &xv);
    void setPv(MatrixXf &Pv);
    void setXf(vector<VectorXf> &xf);
    void setXfi(unsigned long i, VectorXf &vec);
    void setPf(vector<MatrixXf> &Pf);
    void setPfi(unsigned long i, MatrixXf &m);
    void setDa(double *da);
};

#endif