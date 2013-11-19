(defun hms-to-dec (hms-str)
  (let ((hms (split-string hms-str "[°′″NW ]" t)))
    (flet ((to-deg ()
                   (string-to-number
                    (calc-eval (format "deg(%s@ %s' %s\")"
                                       (pop hms) (pop hms) (pop hms))))))
      (list (to-deg) (to-deg)))))
