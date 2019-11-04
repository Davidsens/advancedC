  set terminal pdf           #  definiere Format der Ausgabegraphik
  set output '2.pdf'         #  definiere Namen der output Datei entsprechend Format
  set xzeroaxis              #  zeige y=0 Linie an
  set title "2"              #  gibt dem Kind einen Namen
  set xlabel 'x'             #  beschrifte x-Achse mit x
  set ylabel 'f(x)'          #  beschrifte y-Achse mit f(x)
  set xrange [0:10]          #  setze x-Achsenabschnitt


f(x)=exp(1/x)                #  definiert f(x)

g(x)=exp(x)                  # definiert g(x)

plot f(x) lc 1 lt 1 lw 1, g(x) lc 3 lt 3 lw 3 # plottet f und g mit verschiedenen Farben, Linientypen und breiten
