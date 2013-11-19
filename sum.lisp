;; Annotation is added on 2012-12-06
;; sum (n) is function that calculate the sum of 1 to n.
(defun sum (n)
	(let ((s 0))
		(dotimes (i n s)
			(incf s i))))

;; a test case
(sum 6)
