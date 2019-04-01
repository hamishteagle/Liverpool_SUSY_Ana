import os
from ROOT import TFile, TTree

class SumOfWeightsFixer():

    def main(self):

        dir = "/scratch/msullivan/Release21_Tuples/mc16d/ttbar/"
        for file in os.listdir(dir):
            print(file)

if __name__=="__main__":
    SumOfWeightsFixer().main()
