# THOR #

### Flexible Global Circulation Model to Explore Planetary Atmospheres

*THOR* is a GCM that solves the three-dimensional non-hydrostatic Euler equations on an icosahedral grid. *THOR* was designed to run on Graphics Processing Units (GPUs).

If you use this code please cite: [Mendonca, J.M., Grimm, S.L., Grosheintz, L., & Heng, K., ApJ, 829, 115, 2016](http://iopscience.iop.org/article/10.3847/0004-637X/829/2/115/meta)

Current code owners: Joao Mendonca: joao.mendonca@space.dtu.dk, Russell Deitrick: russell.deitrick@csh.unibe.ch, Urs Schroffenegger: urs.schroffenegger@csh.unibe.ch

###### Copyright (C) 2017-2018 Exoclimes Simulation Platform ######

### BUILD & RUN THOR (TL;DR instructions)

```sh
   $ sudo apt-get install git make gcc g++ cmake nvidia-cuda-toolkit nvidia-utils-390 libhdf5-dev libhdf5-100  libhdf5-serial-dev libhdf5-cpp-100
   $ git clone https://github.com/exoclime/THOR.git
   $ cd THOR
   $ cp Makefile.conf.template Makefile.conf
```
Find the `SM` value of your Nvidia GPU. Decide if you want to run without any physics module `empty` physics module, or the one with radiative transfer, the `multi` module. Then open `Makefile.conf` in a text editor and edit like so:
```
MODULES_SRC := src/physics/managers/<module_type>/
SM:=<SM value of your card> 

``` 
Set `module_type`to `empty` (default) or `multi`.

```
Then head back to the command line and
```sh
   $ make -j8 release
```
Finally, run 
```sh
   $ bin/esp ifile/<config file for your planet>
```
### Furthur information

[View our wiki pages here](https://github.com/exoclime/THOR/wiki)
[Tutorial from ESP Summer School 2019](https://github.com/exoclime/THOR/blob/master/usingthor.pdf)
