Learning Notebook
=================

Install all dependencies with anaconda/miniconda:
```bash
conda create -n cling
conda install glog gflags cmake
conda install -c conda-forge opencv=3.4 eigen xtensor xeus-cling notebook
conda install matplotlib numba pillow scikit-learn scikit-image \
    tensorflow-mkl plotly fabric3
```

Create file `library_path.h` and set your `include` and `lib` folders:
```c++
#pragma cling add_library_path("$HOME/anaconda3/envs/cling/lib")
#pragma cling add_include_path("$HOME/anaconda3/envs/cling/include")
```

Start Jupyter notebook:
```bash
jupyter-notebook
```

Learning OpenCV
---------------

Open notebook `learning-opencv.ipynb`.
