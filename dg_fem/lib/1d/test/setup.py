from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

setup(
  name = 'Demos',
  ext_modules=[
    Extension("tensors",
              sources=["tensors.pyx","testtensor.pxd", "dtensor1.cpp","dtensorBC1.cpp","dtensorBC2.cpp"
,"dtensor2.cpp","dtensor3.cpp","dtensorBC3.cpp","dtensor4.cpp","dtensorBC4.cpp","itensor1.cpp","itensor2.cpp","itensor3.cpp"], # Note, you can link against a c++ library instead of including the source
              include_dirs=["."],
              language="c++"),
    ],
  cmdclass = {'build_ext': build_ext},

)
