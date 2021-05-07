import random as r
import subprocess
import statistics
import os
import shutil
import sys

range_start = -300
range_stop = 300
longueur_liste = int(sys.argv[1])
nombre_executions = 10
dir_name = 'results'

def get_score(start, stop, n):
	result = r.sample(list(range(start, stop)), n)
	result = [str(n) for n in result]
	proc = subprocess.Popen(['./bin/push_swap'] + result, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
	out, err = proc.communicate()
	out = out.decode("utf-8")
	return len(out.split('\n')) - 1, result, out

scores_in_out = []
for i in range(nombre_executions):
	scores_in_out.append(get_score(range_start, range_stop, longueur_liste))
scores_in_out = list(sorted(scores_in_out, key = lambda x: x[0]))

if os.path.isdir(dir_name):
	shutil.rmtree(dir_name)
os.mkdir(dir_name)

for i, (score, algo_in, algo_out) in enumerate(scores_in_out):
	 # fin = open(os.path.join(dir_name, str(i) + '_in_score_' + str(score)), 'w')
	 fin = open(os.path.join(dir_name, str(i) + '_in'), 'w')
	 fin.write(' '.join(algo_in))
	 fin.close()
	# # fout = open(os.path.join(dir_name, str(i) + '_out_score_' + str(score)), 'w')
	# fout = open(os.path.join(dir_name, str(i) + '_out'), 'w')
	# fout.write(algo_out)
	# fout.close()

scores, _, _ = zip(*scores_in_out)

f = open(os.path.join(dir_name,'moyenne'), 'w')
f.write("moyenne :" + str(statistics.mean(scores)) + '\n')
# f.write("max :" + str(max(scores)))
f.close()

print("moyenne :", statistics.mean(scores))
# print("max :", max(scores))
