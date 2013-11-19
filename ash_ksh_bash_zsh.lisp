(setq my-sh-alist '((1 . ksh) (2 . bash) (3 . zsh)))

(global-set-key [f9] 'my-sh-exec)
(defun my-sh-exec nil
  (interactive)
  (with-current-buffer
      (set-buffer "*result*")
    (erase-buffer)
    (my-sh-exec-recursive my-sh-alist)))

(defun my-sh-exec-recursive (my-sh-alist)
  (when (not (null my-sh-alist))
    (let ((sh (symbol-name (cdr (car my-sh-alist)))))
      (insert (concat sh ":	"))
      (call-process-shell-command sh nil "*result*" t "~/1.sh"))
    (my-sh-exec-recursive (cdr my-sh-alist))))


