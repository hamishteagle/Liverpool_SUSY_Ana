import ROOT
ROOT.PyConfig.IgnoreCommandLineOptions = True
ROOT.gROOT.SetBatch(True)
import json
import os
import glob
import copy
import unittest
__author__ = "Giordon Stark-Taken from MBJ analysis"
__doc__    = """Testing script for continuous integration steps"""

class MBJBase(unittest.TestCase):
  # we want a full diff
  maxDiff = None
  args = None
  # preserve location of this script
  __location__ = os.path.realpath(os.path.join(os.getcwd(), os.path.dirname(__file__)))

  # get path name for JSON
  @staticmethod
  def get_json_path(test_type, *args):
    ''' For the given test type, will look for (in order of decreasing priority):
        - /path/to/MBJ_Analysis/tests/<args.process>/<test_type>.json
        - /path/to/MBJ_Analysis/tests/default/<test_type>.json

        or raise an error if no suitable JSON file could be found.
    '''
    basename = '{0:s}.json'.format(test_type)
    specific_file = os.path.join(MBJBase.__location__, MBJBase.args.process, basename)
    default_file  = os.path.join(MBJBase.__location__, 'default', basename)
    if os.path.isfile(specific_file):
      return specific_file
    if os.path.isfile(default_file):
      return default_file

    raise IOError('Missing specific/default file for test type "{0:s}" and process "{1:s}"'.format(test_type, MBJBase.args.process))

  # use this instead of file() to automatically prepend paths correctly
  @staticmethod
  def get_json(test_type, *args):
    ''' For the given test type, will look for /abs/path/to/MBJ_Analysis/tests/<process>/<test_type>.json'''
    return json.load(file(MBJBase.get_json_path(test_type, *args)))

class TestHistFitter(MBJBase):
  '''Tests for histfitter output file'''
  def setUp(self):
    hf_outputs = glob.glob(os.path.join(MBJBase.args.submit_dir, 'data-output_histfitter/*.root'))
    if len(hf_outputs) == 0: raise IOError('Cannot find the histfitter outputs. Searched in "{0:s}"'.format(MBJBase.args.submit_dir))
    self.f = ROOT.TFile.Open(hf_outputs[0])

  def test_cutflow(self):
    '''Is the raw cutflow what we expect?'''
    def error_msg(names, cutflow, expected):
      msg = ['The cutflows do not match.\n{0:20s}{1:>20s}{2:>20s}'.format('','Got','Expected')]
      for name, got, expected in zip(names, cutflow, expected):
        msg.append('{0:20s}{1:20.6f}{2:20.6f}'.format(name, got, expected))
      msg.append('')
      return '\n'.join(msg)+(json.dumps(cutflow, indent=4, sort_keys=True))

    names = ['metadata unweighted',
             'metadata weighted',
             'sum of weights',
             'input unweighted',
             '(data) GRL',
             '(data) detector',
             '',
             '',
             'trigger',
             'bad jet',
             'bad muon',
             'cosmic muon',
             'standard selection',
             'nominal selection',
             'histfitter selection']
    expected = self.get_json('cutflow')
    cutflow = [self.f.cut_flow.GetBinContent(i) for i in range(1, 16)]

    jsonfile = os.path.join('test_outputs', self.args.process, 'cutflow.json')
    json.dump(cutflow, file(jsonfile, 'w+'), indent=4, sort_keys=True)
    self.assertListEqual(cutflow, expected, msg=error_msg(names, cutflow, expected))
    os.remove(jsonfile)

  def test_weights(self):
    '''Are the weights correct?'''
    def error_msg(weights, expected):
      msg = ['The weights do not match.\n{0:20s}{1:>20s}{2:>20s}'.format('','Got','Expected')]
      for name in weights.iterkeys():
        msg.append('{0:20s}{1:20.6f}{2:20.6f}'.format(name, weights[name], expected[name]))
      msg.append('')
      return '\n'.join(msg)+(json.dumps(weights, indent=4, sort_keys=True))

    expected = self.get_json('weights')
    weights = {weight: 0.0 for weight in expected.keys()}
    c = ROOT.TCanvas("test_weights", "test_weights")
    for name in weights.iterkeys():
      storage = ROOT.TH1F("storage"+name, "storage"+name, 1, 0, 10000000)
      self.f.nominal.Draw("1>>storage"+name, "1*(weight_"+name+")")
      weights[name] = storage.Integral()
      c.Clear()
    del c

    jsonfile = os.path.join('test_outputs', self.args.process, 'weights.json')
    json.dump(weights, file(jsonfile, 'w+'), indent=4, sort_keys=True)
    self.assertDictEqual(weights, expected, msg=error_msg(weights, expected))
    os.remove(jsonfile)

  def test_yields(self):
    '''Are the yields correct for various selections?'''
    def error_msg(yields, expected):
      msg = ['The yields for different cuts do not match.\n{0:20s}{1:>10s}{2:>10s}'.format('','Got','Expected')]
      for name in yields.iterkeys():
        msg.append('{0:20s}{1:10d}{2:10d}'.format(name, yields[name]['yield'], expected[name]['yield']))
      msg.append('')
      return '\n'.join(msg)+(json.dumps(yields, indent=4, sort_keys=True))

    expected = self.get_json('yields')
    yields = copy)

  def test_branches(self):
    '''Do we have the required branches in HistFitter?'''
    def error_msg(branches, expected):
      msg = ['The list of branch names do not match.']
      msg.append('  Branches missing:    {0:s}'.format(', '.join([b for b in expected if b not in branches])))
      msg.append('  Unexpected branches: {0:s}'.format(', '.join([b for b in branches if b not in expected])))
      msg.append('')
      return '\n'.join(msg)+(json.dumps(branches, indent=4, sort_keys=True))

    expected = sorted(self.get_json('branches'))
    branches = sorted(parser.add_argument('-p','--process', required=True, metavar='process', type=str, help='Process being looked at')
  parser.add_argument('-s','--submit-dir', required=False, metavar='submitDir', type=str, help='Submit directory location', default='submitDir')

  args, remaining_args = parser.parse_known_args()
  MBJBase.args = args

if __name__ == '__main__':
    unittest.main(argv=sys.argv[:1] + remaining_args)
