import os
import subprocess
from pathlib import Path

from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext as build_ext_orig


class CMakeExtension(Extension):
    def __init__(self, name, source_dir, lib_dir, products):
        super().__init__(name, sources=[])
        self.source_dir = source_dir
        self.lib_dir = os.path.join(source_dir, lib_dir)
        if not isinstance(list, tuple):
            products = [products]
        self.products = products


class build_ext(build_ext_orig):
    def run(self):
        for ext in self.extensions:
            self.build_cmake(ext)

    def build_cmake(self, ext):
        source_dir = os.path.abspath(ext.source_dir)

        if not os.path.exists(self.build_temp):
            os.makedirs(self.build_temp)

        subprocess.check_call(["cmake", source_dir], cwd=self.build_temp)
        subprocess.check_call(["cmake", "--build", "."], cwd=self.build_temp)

        for product in ext.products:
            source_file = os.path.join(self.build_temp, product)
            target_file = os.path.join(self.build_lib, ext.lib_dir, product)
            self.copy_file(source_file, target_file)


setup(
    name="example",
    version="0.1",
    packages=["example"],
    ext_modules=[CMakeExtension("_c", source_dir="", lib_dir="example", products="_c.cpython-36m-x86_64-linux-gnu.so")],
    cmdclass={"build_ext": build_ext},
)