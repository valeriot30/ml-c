#ifndef METRICS_H
#define METRICS_H


#define ACCURACY(cp, wp) (cp / (cp + wp))

#define PRECISION(tp, fp) (tp / (fp + tp))

#define RECALL(tp, fn) (tp / (tp + fn))

#define F1_SCORE(prec, recall) (2 * ((prec * recall) / (prec + recall)))


#endif