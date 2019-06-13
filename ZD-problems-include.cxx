// Gezmat - Generator of sets of mathematical and other problems
// Gezmat - Generator zestawów zadań matematycznych i innych

/*
  THIS FILE IS FOR AUTHORS OF PROBLEMS

  In this file (your-problems-include.cxx) prepare your problems. 

  Faster compilation. To compile only your problems comment lines with #include of other problems in gezmat.cxx in  
  void createProblemGeneratorMap ()
  function.
 
  If you want your problems to be included in the main Gezmat edition, send them to the Gezmat coordinator Piotr Niezurawski (e-mail: Piotr.Niezurawski@pionie.pl or Piotr.Niezurawski@pionie.com). Please, note that sometimes id of the problem will be changed, there may be small changes as well, all major changes will be agreed with you. 

  For more information about licence of Gezmat see the file LICENCE.txt in the package.

  Start: 2017.05.27
  Last modification: 2017.08.22

  Do not remove this header.
*/

// Function to avoid the "unused variable" warnings in case you comment the includes with other problems in gezmat.cxx
avoid_unused_warning(radbydeg);
avoid_unused_warning(degbyrad);
avoid_unused_warning(piby2);

// =============================================================================================
// Problems written by you


// Droga do szkoły

addProblem
("pl-prędkość-droga-czas-00000700", // ID (string)
 "Droga do szkoły", // Title (string)
 "Zofia Drabek", // Authors (string)
 "2018-04-06", // Date of the last update (string)
 1, // Difficulty (int)
 []{ // Lambda expression (returns vector<string>)
     
  
  int v_r = r(15,20); // szybkość roweru [km/h]
  int v_s = v_r + r(1,8); // szybkość średnia [km/h]
  int v_a = v_s*v_r*100/(2*v_r-v_s); // szybkość autobusu *100 [km/h] 
                                     // źle  przybliża
       
  string text = "Jasiu pokonuje swoją drogę do szkoły ze średnią szybkością $";
  text += s(v_s);
  text += "$ km/h. Pierwszą część drogi pokonuje rowerem miejskim, a drugą autobusem. Oba odcinki drogi są sobie równe. Rowerem porusza się ze średnią szybkością $";
  text += s(v_r);
  text += "$ km/h. Oblicz średnią szybkość jazdy autobusem. Wynik podaj z dokładnością do $2$ cyfr znaczących.";

  vector<string> pV;
  pV.push_back(text);


 // Wskazówka
  text = "Zastanów się, w jaki sposób obliczyć średnią szybkość przy znanej szybkości autobusu i roweru. Możesz prowadzić przekształcenia wzorów tak, jakby dystans przejechany przez Jasia do szkoły był znany, zobaczysz, że w późniejszych obliczeniach ten dystans nie będzie istotny.";
  pV.push_back(text);

// Wskazówka
  text = R"qwerty(
  
Przyjmijmy oznaczenia: $v_{a}$ - szybkość autobusu, $v_{r}$ - szybkość jazdy rowerem, $v$ - szybkość średnia, $s$ - długość całej drogi Jasia do szkoły, $t_{a}$ - czas jazdy autobusem, $t_{r}$ - czas jazdy rowerem. \\
Średnia szybkość jest to iloraz całej drogi i całego czasu, tj. 
\[ 
	v=\frac{s}{t_{a}+t_{r}}, \qquad t_{a}=\frac{s}{2v_{a}}, \qquad t_{r}=\frac{s}{2v_{r}}.
\]
Podstawiając odpowiednio czas jazdy autobusem oraz czas jazdy rowerem do pierwszego z równań, otrzymujemy równanie:
\[
	v=\frac{s}{\frac{s}{2v_{a}}+\frac{s}{2v_{r}}}.
\]
Po skróceniu przez $s$ i uproszczeniu równania otrzymujemy:
\[
     v=\frac{2}{\frac{1}{v_{a}}+\frac{1}{v_{r}}}.
\]
Jest to tzw.~średnia harmoniczna. Końcowy wzór na prędkość autobusu to:
\[
	v_{a}=\frac{vv_{r}}{2v_{r}-v}.
\]
  
  )qwerty";
  pV.push_back(text);
 


 
  // Odpowiedź
  text = "Autobus jedzie ze średnią szybkością ok. $";
  text += s(o(v_a,2),2);
  text += "$ km/h.";

  pV.push_back(text);

  return pV;
  
 } // End of lambda expression
 ); // End of addProblem

//--------------------------------------------------------------------------

// Podgrzewanie lodu
addProblem 
("pl-ciepło-0000007", // ID (string)
 "Podgrzewanie lodu", // Title (string)
 "Zofia Drabek", // Authors (string)
 "2018-05-06", // Date of the last update (string)
 3, // Difficulty (int)
 []{ // Lambda expression (returns vector<string>)

  int T_p, m, t, P, n, T, k;

  int c_l = 2100; // ciepło właściwe lodu [J/(kg*K)]
  int L = 330000; // ciepło topnienia lodu [J/kg]
  int c_w = 4200; // ciepło właściwe  wody [J/(kg*K)]
  string odp;
  double T_k; //temperatura końcowa [st. celsjusza :100]
  double Q_0; // ciepło dostarczone przez kuchenkę 
  double Q_1; // potrzebne ciepło pobrane do ogrzania lodu do temperatury 0 st. Celsjusza
  double Q_2; // ciepło potrzebne do roztopienia lodu
  double X, Y, Z; // ograniczenia czasu t

do{
  k = r(0,2);
  switch(k){
    case 0:
      P = r(8,10); //moc [kW]
      n = r(30,50); // sprawność [%] :100
      m = r(3,6); // masa [kg]
      T_p = r(-35,-20); //temperatura początkowa lodu [st. Celsjusza]
      X = -c_l*m*T_p/(P*n*60);
      t = r(1,dtoi(floor(X))); // czas ogrzewania [:10 min]
      Q_0 = itod(P)*t*n*60; // ciepło dostarczone
      T_k = (itod(T_p) + Q_0/(c_l * m))*1000; // [st. Celsjusza] :1000
      T = o(dtoi(T_k),2);
      odp = "Lód nie roztopił się, jego temperatura wynosi $";
      odp += s(T,3);
      odp += "^\\circ$C.";
    break;
    case 1:
      m = r(1,4); // masa lodu [kg]
      P = r(9,12); // moc kuchenki [kW]
      n = r(40,60); // sprawność [%] :100
      T_p = r(-25,-10); // temperatura początkowa [st. Celsjusza]
      X = -c_l*m*T_p/(P*n*60);
      Y = itod(m)*L/(P*n*60);
      t = r(dtoi(ceil(X)),dtoi(floor(X+Y))); // czas ogrzewania [:10 min]
      T_k = 0;
      odp = "Otrzymano mieszaninę lodu i wody w temperaturze $0^\\circ$C";
    break;
    case 2:
      m = r(1,4); // masa lodu [kg]
      P = r(8,12); // moc kuchenki [kW]
      n = r(40,60); // sprawność [%] :100
      T_p = r(-20,-5); //temperatura początkowa lodu [st. Celsjusza]
      X = -c_l*m*T_p/(P*n*60);
      Y = itod(m)*L/(P*n*60);
      Z = itod(m)*c_w*100/(P*n*60);
      t = r(dtoi(ceil(X+Y)),dtoi(floor(X+Y+Z))); // czas ogrzewania [:10 min]
      Q_0 = itod(P)*t*n*60;
      Q_1 = itod(m)*c_l*T_p*(-1);
      Q_2 = itod(m)*L;
      T_k = ((Q_0 - Q_1 - Q_2)/(itod(c_w) * m))*1000;// [st. Celsjusza] :1000
      T = o(dtoi(T_k),2);
      odp = "Lód roztopił się. Temperatura wody wynosi $";
      odp += s(T,3);
      odp += "^\\circ$C.";    
    break;
    default:
      m = 0;
      P = 0;
      t = 0;
      n = 0;
      T_p = 0;
      T_k = 0;
    break;
  }
}while(T_k>=10000);

  string text = "W naczyniu znajdował się lód o masie ";
  text += s(m);
  text += " kg w temperaturze $";
  text += s(T_p);
  text += "^\\circ$C. Naczynie to postawiono na kuchence gazowej i ogrzewano przez ";
  text += s(o(dtoi(t*10),2),2);
  text += " min. Moc kuchenki wynosiła "; 
  text += s(P);
  text += " kW. Sprawność procesu ogrzewania zawartości naczynia była równa ";
  text += s(n);
  text += R"qwerty(\%. 
  \begin{enumerate}[a)]
\item Czy lód się stopił?
\item Oblicz temperaturę końcową zawartości naczynia. Wynik podaj z dokładnością do $2$ cyfr znaczących.
\end{enumerate}
W obliczeniach pomiń ciepło oddane do otoczenia i naczynia. Przyjmij, że ciepło topnienia lodu wynosi $L= 330$ kJ/kg, ciepło właściwe lodu $c_{l}=2100$ J/(kg $\cdot$ K), a ciepło właściwe wody $c_{w}=4200$ J/(kg $\cdot$ K).
 )qwerty";

  vector<string> pV;
  pV.push_back(text);

// Wskazówka
  text = "Należy skorzystać z zależności wynikających z bilansu cieplnego. Zwróć uwagę na to, które wielkości w obliczeniach będą dodatnie, a które ujemne.";

  pV.push_back(text);

// Wskazówka
  text = R"qwerty(

To, czy lód się roztopi, zależy przede wszystkim od ilości ciepła, które dostarczymy do układu
\[
    Q_{0}=Pt\eta,
\]
gdzie $P$ jest mocą kuchenki, $t$ czasem ogrzewania, a $\eta$ sprawnością procesu ogrzewania.\\
Jeżeli ciepło to jest mniejsze od ciepła potrzebnego do ogrzania lodu do temperatury topnienia ($0^\circ$C), to w naczyniu nadal znajduje się lód, tylko w wyższej temperaturze. Ciepło potrzebne do ogrzania lodu do temperatury topnienia $Q_{1}$ można obliczyć za pomocą zależności
\[
	Q_{1}=mc_{l}(0^\circ\text{C}-T_{p}),
\]
gdzie $m$ jest masą lodu, a $T_{p}$ to temperatura początkowa lodu w stopniach Celsjusza.\\
Jeżeli $Q_{0}<Q_{1}$, to temperaturę końcową $T_{k}$ można obliczyć w następujący sposób
\[
	Q_{0}=mc_{l}(T_{k}-T_{p})
\]
\[
	T_{k}=\frac{Q_{0}}{mc_{l}}+T_{p}
\]
Jeżeli nie, to należy sprawdzić, czy ciepło $Q_{0}$ jest większe od sumy ciepła potrzebnego do ogrzania lodu do temperatury topnienia $Q_{1}$ oraz ciepła potrzebnego do roztopienia lodu $Q_{2}$.
\[
	Q_{2}=mL.
\]
Jeżeli $Q_{1}<Q_{0}<Q_{1}+Q_{2}$, to otrzymano mieszaninę lodu i wody o temperaturze końcowej $T_{k}=0^\circ$C.\\
Jeżeli jednak $Q_{1}+Q_{2}<Q_{0}$, to lód roztopił się, a temperaturę końcową można obliczyć w~następujący sposób:
\[
  Q_{0}=Q_{1}+Q_{2}+mc_{w}(T_{k}-0^\circ\text{C})
\]
\[
	Q_{0}=mc_{l}(0^\circ\text{C}-T_{p})+mL+mc_{w}(T_{k}-0^\circ\text{C})
\]
\[
	T_{k}=\frac{Q_{0}+mc_{l}T_{p}-mL}{mc_{w}}
\]

  )qwerty";
  pV.push_back(text);


  // Odpowiedź
  text = odp;

  pV.push_back(text);

  return pV;
  
 } // End of lambda expression
 ); // End of addProblem


//--------------------------------------------------------------------------
//Łamigłówka z elektrostatyki
addProblem 
("pl-elektrostatyka-0000100", // ID (string)
 "Łamigłówka z elektrostatyki", // Title (string)
 "Zofia Drabek", // Authors (string)
 "2018-05-25", // Date of the last update (string)
 1, // Difficulty (int)
 []{ // Lambda expression (returns vector<string>)
     
       
  string text = "Do dyspozycji masz uziemienie oraz trzy jednakowe metalowe kule, dwie z nich naładowane są ładunkiem $Q$, a trzecia ładunkiem $-Q$. Otrzymaj na jednej z nich ładunek $\\frac{3}{8}Q$.";

  vector<string> pV;
  pV.push_back(text);
  
  // Odpowiedź
  text = R"qwerty(Najszybsza droga do uzyskania na jednej kuli ładunku o wartości $\frac{3}{8}Q$:
  \begin{enumerate}[I]
   \item połączenie kul o ładunkach $Q$ i $-Q$
   \item połączenie kul o ładunkach $0$ i $Q$
   \item połączenie kul o ładunkach $\frac{1}{2}Q$ i $0$
   \item połączenie kul o ładunkach $\frac{1}{2}Q$ i $\frac{1}{4}Q$
   \item i w ten sposób uzyskaliśmy ładunek $\frac{3}{8}Q$.
  \end{enumerate}
Uwaga! Za każdym razem łączymy kule na tyle długo, aby uzyskać taki sam ładunek na obydwu kulach.
)qwerty";

  pV.push_back(text);

  return pV;
  
 } // End of lambda expression
 ); // End of addProblem


//--------------------------------------------------------------------------

//Obwód w kształcie okręgu
addProblem 
("pl-prąd-0000100", // ID (string)
 "Obwód w kształcie okręgu", // Title (string)
 "Zofia Drabek", // Authors (string)
 "2018-04-15", // Date of the last update (string)
 2, // Difficulty (int)
 []{ // Lambda expression (returns vector<string>)
     
  //zmienne
  int l = r(8,20); // w cm
  int b = r(10,90); // wartość do podania w Asymptote
  int a = 2*b; // kąt w stopniach
  int U = r(12,15); // napięcie na baterii *10
  int ro = r({172,282}); // opór właściwy substancji *10^10
  int S = r(3,3000);
  S =  o(S,2); // pole przekroju poprzecznego w 100*mm^{2}
  double P = (double)U*U*o(S,2)*360*360*100000/(ro*l*a*(360-a));
  int p = dtoi(P);
       
  string text = "Kawałek drutu o długości $";
  text += s(l);
  text += "$ cm wykonany z jednorodnego przewodnika wygięto w kształt okręgu.  Pomiędzy punktami A i B włączono baterię. Położenie punktów A i B przedstawia rysunek, $\\alpha=";
  text += s(a);
  text += "^\\circ$. Napięcie $U$ na baterii wynosi $";
  text += s(U,1);
  text += "$ V. Oblicz moc wydzielaną w tym obwodzie. Opór właściwy zastosowanej substancji wynosi $\\rho=";
  text += s(ro, 2);
  text += "\\cdot 10^{-8}$ $\\Omega \\cdot $m. Pole powierzchni przekroju poprzecznego drutu wynosi $S=";
  text += s(o(S,2),2);
  text += "$ mm$^{2}$. Pomiń opór elektryczny przewodów połączeniowych oraz opór wewnętrzny baterii.";
  // Rysunek
  text += R"Pniez( 

\begin{center}
  \begin{asy}[width=0.5\textwidth]
import geometry;

int a=)Pniez";
  text += s(b);
  text += R"Pniez(;

pair O = (0,0); 
pair A = dir(-a);
pair B = dir(a);

draw(circle(O,1.0), linewidth(1.5));
draw(A--O--B,dashed);

draw("$\alpha$",arc(A,O,B,0.3));
dot("A", A, SE);
dot("B", B, NE);


real d = 0.02; // połowa odległości pomiędzy kreskami w symbolu baterii
real e = 0.05; // 1/2 długości krótszej i 1/4 długości dłuższej kreski  w symbolu baterii
real f = 1.5; // współrzędna x położenia źródła prądu

pair C = (f, B.y); // prawy górny wierzchołek przewodów połączeniowych
pair D = (f, A.y); // prawy dolny wierzchołek przewodów połączeniowych
pair E = (f, d); // środek dłużeszj kreski w symbolu baterii
pair F = (f, -d); // środek krótszej kreski w symbolu baterii
pair G = (f+2*e, d); // lewy wierzchołek dłużeszj kreski w symbolu baterii
pair H = (f-2*e, d); // prawy wierzchołek dłużeszj kreski w symbolu baterii
pair I = (f+e, -d); // lewy wierzchołek krótszej kreski w symbolu baterii
pair J = (f-e, -d); // prawy wierzchołek krótszej dłużeszj kreski w symbolu baterii

draw(B--C--E);
draw(F--D--A);
draw(G--H);
draw(I--J);

pair U = (f+2*e,0); // środek symbolu baterii
label("$U$", U, E);
  \end{asy}
\end{center}

)Pniez";

  vector<string> pV;
  pV.push_back(text);
 
  // Wskazówka
  text = R"qwerty(
Do obliczenia mocy wydzielonej w tym obwodzie wykorzystamy wzór:
\[
    P=IU,
\] gdzie $P$ jest mocą, $I$ natężeniem prądu, $U$ napięciem źródła. 
)qwerty";
  pV.push_back(text);

  // Wskazówka
  text = R"sofi(
Po zastosowaniu prawa Ohma wzór na moc będzie wyglądał następująco:
\[
    P=\frac{U^{2}}{R_{z}}=U^{2} \cdot \frac{1}{R_{z}},
\]
 gdzie $R_{z}$ jest oporem zastępczym. 
Zauważmy, że nasz układ jest układem dwóch oporników połączonych równolegle, a~opór każdego z~nich można obliczyć z zależności $R=\frac{\rho l_{i}}{S}$, gdzie $l_{i}$ jest długością przewodnika, a~$S$ polem powierzchni przekroju poprzecznego.
)sofi";
  pV.push_back(text);
  // Wskazówka
  text = R"sofi(
 Długość przewodnika $l_{i}$ jest równa długości łuku, czyli długości całego drutu (okręgu) $l$ przemnożonego przez $\frac{\alpha}{360^\circ}$ lub odpowiednio $\frac{360^\circ - \alpha}{360^\circ}$. Odwrotność oporu zastępczego obliczymy więc następująco:
\[
    \frac{1}{R_{z}}=\frac{1}{R_{1}}+\frac{1}{R_{2}}
=\frac{ S }{{ \rho l \frac{\alpha}{360^\circ}} } + \frac{ S }{ \rho l \frac
{360^\circ - \alpha}{360^\circ} }
=\frac{ S \cdot (360^\circ)^{2} }{ \rho l (360^\circ - \alpha)\alpha },
\] gdzie przez $R_{1}$ i $R_{2}$ oznaczam opory poszczególnych fragmentów obwodu. 
Ostateczny wzór na moc to:
\[
    P = \frac{ U ^{2} S \cdot (360^\circ)^{2}  }{ \rho l (360^\circ - \alpha)\alpha}
\]
)sofi";


  pV.push_back(text);
 
  // Odpowiedź
  text = "Moc wydzielana w układzie wynosi ok. $";
  text += s(o(p,3),3);
  text += "$ W.";

  pV.push_back(text);

  return pV;
  
 } // End of lambda expression
 ); // End of addProblem

//Wyciąganie bloku z morza
addProblem 
("pl-mechanika-0000100", // ID (string)
 "Wyciąganie bloku z morza", // Title (string)
 "Zofia Drabek", // Authors (string)
 "2018-05-21", // Date of the last update (string)
 3, // Difficulty (int)
 []{ // Lambda expression (returns vector<string>)
     
  //zmienne
  int a = r(3,7);//w m
  int b = r(3,7);//w m
  int h = r(3,10);//w m
  int H = h + r(1,12);//w m
  int ro = r(2000,2200);//gęstość betonu w kg/m^3
  int V = a*b*h; // objętość bloku m^3
  int m = ro*V; // masa bloku kg
  int g = 10; //przyspieszenie ziemskie m/s^2
  double mg = m*g;
  double F_w = g*V*1030; // siła wyporu dla bloku zanurzonego w wodzie w całości
  double W_d = ((m*g-1030*V*g)*(H-h))+(h*(2*m*g-1030*V*g)/2); //1030 to gęstość wody morskiej w kg/m^3

  string text = "Na poziomym dnie morza spoczywa prostopadłościenny betonowy blok o wymiarach podstawy $a=";
  text += s(a);
  text += "$ m, $b=";
  text += s(b);
  text += "$ m oraz wysokości $h=";
  text += s(h);
  text += "$ m. Głębokość wody w tym miejscu wynosi $H = ";
  text += s(H);
  text += R"qwerty($ m. Postanowiono wyciągnąć blok z wody.)qwerty";
  // Rysunek
  text += R"Pniez( 
\begin{center}
  \begin{asy}[width=0.5\textwidth]
import trembling; 
size(7cm,0); 
  
real h=0.8;
real l=0.7;
real g = 0.5;
 
pair pA=(-l,0); 
pair pB=(l,0); 

//powierzchnia wody
tremble tr=tremble(angle=10,frequency=0.1,random=50,fuzz=1);
path waterline=tr.deform(pA..pB);  
path water=waterline--(l,-h)--(-l,-h)--(-l,0)--cycle; 
path container=(l,1/7)--(l,-h)--(-l,-h)--(-l,1/7); 

//woda  
fill(water,mediumgrey+opacity(0.5)); 
draw(waterline); 

//prostopadłościan
draw(container,linewidth(1.5)); 

real a = 0.25;
real H = 0.5;

path X=(a,-h)--(a,H-h)--(-a,H-h)--(-a,-h);
draw(X);

label("$a$",(0,H-h),N);
label("$h$",(a,H/2-h),E);

pair G1 = (-l-0.1,0);
pair G2 = (G1.x,-g);
path G = G1--G2; // g
draw(Label("$g$"), G, Arrow);

  \end{asy}
\end{center}
)Pniez";

  text += R"qwerty( 
\begin{enumerate}[a)]
\item Przedstaw na wykresie zależność minimalnej siły $F$ potrzebnej do wyciągnięcia bloku od położenia dolnej podstawy bryły $y$.
\item Oblicz minimalną pracę, jaką należy wykonać w celu wyciągnięcia bloku z wody. Wynik podaj w kJ z dokładnością do 3 cyfr znaczących.
\end{enumerate}
Przyjmij, że gęstość wody  morskiej wynosi $\rho_{w} = 1030$ $\frac{\text{kg}}{\text{m}^{3}}$, przyspieszenie ziemskie $g = 10$ $\frac{\text{m}}{\text{s}^{2}}$ oraz gęstość betonu $\rho_{b}=)qwerty";
  text += s(ro);
  text += "$ $\\frac{\\text{kg}}{\\text{m}^{3}}$. Wyciąganie było bardzo powolne oraz odbywało się ruchem jednostajnym, pomiń opory ruchu oraz wpływ powietrza.";
  
  string asyCode = "";
// string asymptoteGraph(string xLabel, string xmin, string xmax, string xStep, string xstep, string yLabel, string ymin, string ymax, string yStep, string ystep, string asyCode, string asyOptions = "width=0.9\\textwidth, height=0.4\\textheight, keepAspect=false")
text += asymptoteGraph("$y$/m", "0", to_string(1.1*H), "2", "1", "$F$/N", "0", to_string(1.1*mg), "500000", "250000", asyCode, "width=0.9\\textwidth, height=0.4\\textheight, keepAspect=false");

  vector<string> pV;
  pV.push_back(text);
 
  // Wskazówka
  text = R"sofi(
a) Należy zastanowić się, jak siła wyciągająca zmieniała się podczas wyciągania. W dół cały czas działa  siła ciężkości $Q=mg$. Do góry działa siła wyporu. Jej wartość nie jest stała, zależy od objętości zanurzenia $V_{z}$, która się zmienia.
)sofi";
  pV.push_back(text);

  // Wskazówka
  text = R"sofi(
Wyciąganie bloku można podzielić na 3 etapy:
\begin{enumerate}[1)]
\item gdy blok jest cały zanurzony (dolna podstawa znajduje się na wysokości od  0 do  $H-h$)
\item gdy blok jest częściowo zanurzony w wodzie (dolna podstawa znajduje się na wysokości od $H-h$ do $H$)
\item gdy blok jest ponad taflą wody (dolna podstawa znajduje się powyżej $H$) 
\end{enumerate}
)sofi";
  pV.push_back(text);

  // Wskazówka
  text = R"sofi(
Wartość siły wyporu w kolejnych etapach wyraża się wzorami:
\begin{enumerate}[1)]
\item $F_{w}=\rho_{w} \cdot g \cdot V_{z} = \rho_{w} \cdot g \cdot a \cdot b \cdot h$ i jest stała,
\item $F_{w}=\rho_{w} \cdot g \cdot V_{z} $, w  tym  przypadku jednak objętość zanurzenia $V_{z}$ nie jest stała, lecz zależy od wysokości $y$, na której znajduje się w danej chwili dolna podstawa prostopadłościanu, więc $F_{w}=\rho_{w} \cdot g \cdot a \cdot b \cdot (H-y)$,
\item $F_{w}=0$.
\end{enumerate}
Na podstawie powyższych wyrażeń oraz zależności $F=Q-F_{w}$, gdzie $F$ jest siłą  wyciągającą, należy narysować wykres zgodnie z poleceniem w podpunkcie  a).
)sofi";
  asyCode = R"sofi( real x1 = 0, x2 = )sofi";
  asyCode += to_string(H-h);
  asyCode += ", x3 = ";
  asyCode += to_string(H);
  asyCode +="; real y1 = ";
  asyCode += to_string(mg-F_w);
  asyCode += ", y2 =";
  asyCode += to_string(mg);
  asyCode += R"sofi(;
path vline = (x1, y1)--(x2, y1)--(x3,y2);
draw(vline, linewidth(1.5));


)sofi";

// string asymptoteGraph(string xLabel, string xmin, string xmax, string xStep, string xstep, string yLabel, string ymin, string ymax, string yStep, string ystep, string asyCode, string asyOptions = "width=0.9\\textwidth, height=0.4\\textheight, keepAspect=false")
text += asymptoteGraph("$y$/m", "0", to_string(1.1*H), "2", "1", "$F$/N", "0", to_string(1.1*mg), "500000", "250000", asyCode, "width=0.9\\textwidth, height=0.4\\textheight, keepAspect=false");

  pV.push_back(text);

// Wskazówka
  text = R"sofi(
b) Pracę $W$ można wyznaczyć jako pole powierzchni pod wykresem $F(y)$ dla $y \in [0;H]$. Można również obliczyć ją, uwzględniając wartość siły w kolejnych etapach:
\begin{enumerate}[1)]
\item Na blok działa stała siła wyciągająca i działa na odcinku o długości $H-h$ \[W=(mg-\rho_{w} \cdot g \cdot a \cdot b \cdot h) \cdot (H-h).\] \\
\item siła wyciągająca nie jest stała, ale wzrasta jednostajnie (zobacz, jak to wygląda na wykresie), dlatego możemy użyć jej wartości średniej.
\[
    W = \frac{(mg-\rho_{w} \cdot g \cdot a \cdot b \cdot h)+(mg-0)}{2} h
\]
\end{enumerate}
W celu obliczenia całej pracy należy zsumować wartości otrzymane w 1) i 2).
Zauważ, że w 1) obliczyliśmy pole prostokąta, a w 2) pole trapezu.
)sofi";
  pV.push_back(text);
  // Odpowiedź
  text = "b) Minimalna praca potrzebna do wyciągnięcia bloku wynosi około $";
  text += s(o(dtoi(W_d),3),3);
  text += "$ kJ.";

  pV.push_back(text);

  return pV;
  
 } // End of lambda expression
 ); // End of addProblem

//--------------------------------------------------------------------------

//Sanki
addProblem 
("pl-mechanika-0000000", // ID (string)
 "Sanki", // Title (string)
 "Zofia Drabek", // Authors (string)
 "2018-05-25", // Date of the last update (string)
 3, // Difficulty (int)
 []{ // Lambda expression (returns vector<string>)
     
  //zmienne
  int a = r({45,30,60}); // kąt [deg]
  int l = r(50,200); // dł drogi do obliczenia pracy [m]
  int m = r(20,40); // masa dziecko +sanki [kg]
  int mu = r(10,25); //współczynnik tarcia [/100]
  double sin_a, cos_a;
  string sin_a_s, cos_a_s, wsk;
  int g = 10;
  int Q = m*g;

    sin_a = sin(radbydeg*a);
    cos_a = cos(radbydeg*a);
    switch(a){
      case 45:
        sin_a_s = R"sofi(\frac{1}{\sqrt{2}})sofi";
        cos_a_s = R"sofi(\frac{1}{\sqrt{2}})sofi";
        wsk = "Wiemy to na podstawie znajomości stosunków boków w trójkącie równoramiennym prostokątnym.";
        break;
      case 30:
        sin_a_s = R"sofi(\frac{1}{2})sofi";
        cos_a_s = R"sofi(\frac{\sqrt{3}}{2})sofi";
        wsk = "Wiemy to na podstawie znajomości stosunków boków w trójkącie o kątach $30^\\circ$, $60^\\circ$, $90^\\circ$.";
        break;
      case 60:
        cos_a_s = R"sofi(\frac{1}{2})sofi";
        sin_a_s = R"sofi(\frac{\sqrt{3}}{2})sofi";
        wsk = "Wiemy to na podstawie znajomości stosunków boków w trójkącie o kątach $30^\\circ$, $60^\\circ$, $90^\\circ$.";
        break;
      default:
        sin_a_s = " ";
        cos_a_s = " ";
        wsk = " ";
        break;
    }

  double F_d = itod(Q)*mu/(sin_a*100.+cos_a*mu);
  int F = o(dtoi(F_d),2);
  double Q_do_F = sin_a+cos_a*100./mu;
  double W = F*cos_a*l*100; // /100
  int W_i = dtoi(W);
  double mu_d = F*cos_a*100/(Q-F*sin_a); // /100
  int mu_i = dtoi(mu_d);

  string text = "Mama ciągnęła sanki z dzieckiem po śniegu, działając siłą o wartości $F=";
  text += s(F);
  text += "$ N. Sznurek podczas ruchu był cały czas napięty i nachylony do poziomu pod kątem $\\alpha=";
  text += s(a);
  text += "^\\circ$. Masa sanek i dziecka wynosiła $m = ";  
  text += s(m);
  text += R"sofi($~kg. Przyjmij, że przyspieszenie ziemskie wynosi $g=10$ $\frac{\text{m}}{\text{s}^{2}}$ oraz że ruch był jednostajny prostoliniowy i odbywał się w poziomie.)sofi";

// Rysunek
  text += R"sofi( 

\begin{center}
  \begin{asy}[width=0.5\textwidth]


real l = 40; // Length of an brick
real h = 15; // Height of an brick
real d = 10; // poziom sanek
real e = 10; // vertical segment position

// Size of picture

real penWidth = 0.8;
defaultpen(penWidth);

pair R1, R2, R3, R4, A, B, C, E, F, G, H, I, J;
//Brick 1
R1 = (l, -h);
R2 = (0, -h);
R3 = (0, h);
R4 = (l, h);
path Brick1 = R1--R2--R3--R4--cycle;
filldraw(Brick1, opacity(0.7)+lightgrey);
draw((-5,-h)--(5+l,-h));

//Velocity
real angle = )sofi";
  text += s(a);
  text += R"sofi(;
A = (0, 0);
B = (-l,0);
C = 70*dir(180-angle);
path V = A--C;
draw(Label("$\vec{F}$" , 0.4, 1.5NE), V, Arrow);
path L = A--B;
draw(L, gray(0.2)+dashed);

draw("$\alpha$",arc(A,15,180,180-)sofi";
  text += s(a);
  text += R"sofi(),PenMargins);

// Floor
E = (-l/2, -d-h);
F = ((3/2)*l, -d-h);
path Floor = E--F--cycle;
draw(Floor);

//sledge

G = (e,-h);
H = ((l/2)+e,-h);
I = (e,-d-h);
J = ((l/2)+e,-d-h);
draw(G--I);
draw(H--J);
draw((-d,-h){down}..{right}(0,-d-h),linewidth(1.5));
draw((0,-d-h)--(5+l,-d-h),linewidth(1.5));

real g = 40;
pair G1 = (l+30,25);
pair G2 = (G1.x,G1.y-g);
path G = G1--G2; // g
draw(Label("$g$"), G, Arrow);

  \end{asy}
\end{center}

)sofi";
  text += R"sofi(
  \begin{enumerate}[a)]
\item Oblicz pracę, jaką wykonała mama, ciągnąc sanki z dzieckiem na drodze $s=
)sofi";
  text += s(l);
  text += R"sofi($
 m.
\item Na poniższym rysunku przedstawiono następujące siły działające na sanki z dzieckiem: $\vec{F}$ - siła ciągnąca, $\vec{T}$ - siła tarcia, $\vec{Q}$ - siła ciężkości. Brakuje na nim pionowej składowej siły reakcji podłoża $\vec{R}$. Zaznacz ją na tym rysunku, zachowaj odpowiednie proporcje.
\begin{center}
  \begin{asy}[height=0.5\textheight]
import geometry;

real a = )sofi";
  text += s(a);
  text += R"sofi(;

pair O = (0,0);
pair B = dir(180-a); //siła ciągnąca
pair A = (-B.x,0); //tarcie
pair C = (0,-()sofi";
  text += to_string(Q_do_F);
  text += R"sofi()*B.y); //siła ciężkości
pair D = 1.07*(0,-B.y-C.y); //siła reakcji

draw(Label("$\vec{T}$"), O--A, Arrow);
draw(Label("$\vec{F}$"), O--B, Arrow);
draw(Label("$\vec{Q}$"), O--C, Arrow);
draw(Label("$\vec{R}$"), O--D, white, Arrow);

  \end{asy}
\end{center}

\item Oblicz współczynnik tarcia kinetycznego $\mu$ sanek o śnieg.
\end{enumerate}
)sofi";

  vector<string> pV;
  pV.push_back(text);
 
  // Wskazówka
  text = "a) Pamiętaj, że aby obliczyć pracę siły ciągnącej, należy uwzględnić jej składową poziomą (wzdłuż przemieszczenia).";
  pV.push_back(text);

  // Wskazówka
  text = "Długość składowej poziomej siły ciągnącej wynosi $F_{x}=";
  text += cos_a_s;
  text += "F$. ";
  text += wsk;
  text += R"sofi( Pracę można obliczyć za pomocą zależności:
\[
    W=)sofi";
  text += cos_a_s;
  text += R"sofi( Fs.
\]
)sofi";
  pV.push_back(text);

// Wskazówka
text = "b) Skoro sanki poruszają się ruchem jednostajnym, to siła wypadkowa musi być równa $0$.";
pV.push_back(text);

// Wskazówka
text = R"sofi(Składowa pozioma siły ciągnącej $\vec{F_{x}}$ jest równa co do wartości sile tarcia $\vec{T}$. W pionie wartości sił zależą od siebie w następujący sposób:
\[
    R+F_{y}=Q,
\] gdzie $F_{y}$ jest wartością pionowej składowej siły ciągnącej. Zauważ, że siła nacisku, równa co do wartości sile $R$, nie jest równa sile ciężkości sanek z dzieckiem $Q$.\\
Aby skonstruować $\vec{R}$ należy:
\begin{itemize}
\item rozłożyć $\vec{F}$ na składowe (pionową $\vec{F_{y}}$ i poziomą $\vec{F_{x}}$),
\item odmierzyć cyrklem $F_{y}$ oraz odłożyć tę długość na $\vec{Q}$ tak, aby móc odmierzyć długość $Q-F_{y}$, taką właśnie długość ma wektor $\vec{R}$,
\item narysować pionowo do góry wektor o otrzymanej poprzednio długości.
\end{itemize}
)sofi";

pV.push_back(text);

// Wskazówka
text = R"sofi(c) Wartość siły tarcia wynosi $T=\mu R$. Siła wypadkowa jest równa $0$, więc otrzymujemy układ równań z dwoma niewiadomymi ($\mu$ oraz $R$):
\[
    F_{x} = T, \qquad )sofi" + cos_a_s + R"sofi(F=R \mu,
\]
\[
    R+F_{y}=Q, \qquad R+)sofi" + sin_a_s + R"sofi(F = Q,
\] gdzie $\mu$ oznacza współczynnik tarcia. Rozwiązując układ równań, otrzymamy zależność na współczynnik tarcia:
\[
    \mu = \frac{)sofi" + cos_a_s + R"sofi(F}{Q-)sofi" + sin_a_s + R"sofi(F}.
\]
)sofi";
pV.push_back(text);

// Odpowiedź
  text = R"sofi(
  \begin{enumerate}[a)] 
  \item Mama wykonała pracę równą około $)sofi";

  text += s(o(W_i,3),2);
  text += R"sofi(
$ J.
\item ~\\
\begin{center}
  \begin{asy}[height=0.5\textheight]
import geometry;

real a = )sofi";
  text += s(a);
  text += R"sofi(;

pair O = (0,0);
pair B = dir(180-a); //siła ciągnąca
pair A = (-B.x,0); //tarcie
pair C = (0,-()sofi";
  text += to_string(Q_do_F);
  text += R"sofi()*B.y); //siła ciężkości
pair D = (0,-B.y-C.y); //siła reakcji
pair D_0 = 1.07*(0,-B.y-C.y); // tak aby oba rysunki były takiej samej wielkości

draw(Label("$\vec{T}$"), O--A, Arrow);
draw(Label("$\vec{F}$"), O--B, Arrow);
draw(Label("$\vec{Q}$"), O--C, Arrow);
draw(Label("$\vec{R}$"), O--D_0, white, Arrow);
draw(Label("$\vec{R}$"), O--D, red, Arrow);

  \end{asy}
\end{center}

\item Współczynnik tarcia sanek o śnieg wynosi około $)sofi";
  text += s(o(mu_i,2),2);
  text += R"sofi($.
  \end{enumerate}
  )sofi";
  pV.push_back(text);

  return pV;
  
 } // End of lambda expression
 ); // End of addProblem

//---------------------------------------------
//Przejażdżka metrem
addProblem 
("pl-gim-0000000", // ID (string)
 "Przejażdżka metrem", // Title (string)
 "Zofia Drabek", // Authors (string)
 "2018-04-27", // Date of the last update (string)
 1, // Difficulty (int)
 []{ // Lambda expression (returns vector<string>)
     
  //zmienne
  int v_p = r(40,50);//szybkość ucznia wzgl. pociągu [/10 km/h]
  int d = r(10,13); // odległość między początkami kolejnych stacji [*100 m]
  int l = r(110,120);// długość  pociągu
  double u_d = itod(d)*10*v_p/l;//szybkość pociągu wzgl stacji metra
  int u = o(dtoi(u_d*100),3);
  int v_z = u-(v_p*10); // szybkość ucznia względem ziemi

  string text = "Uczeń wsiadł do metra na początku pociągu. Postanowił przejść podczas jazdy na jego koniec korytarzem o długości $l=";
  text += s(l); 
  text += "$ m. Gdy tam dotarł, pociąg wjechał na kolejną stację. Uczeń szedł ze średnią szybkością $v_{p}=";
  text += s(v_p,1);
  text += "$ $\\frac{\\text{km}}{\\text{h}}$ względem pociągu. Pociąg przejechał drogę  $s=";
  text += s(d);
  text += "00$ m. Oblicz średnią szybkość, z jaką jechał pociąg względem stacji metra $u$, oraz średnią szybkość ucznia względem ziemi $v_{z}$.";

  vector<string> pV;
  pV.push_back(text);
 
  // Wskazówka
  text = R"sofi(Aby otrzymać średnią szybkość jazdy pociągu, należy obliczyć iloraz całej drogi pokonanej przez pociąg $s$ oraz czasu przejazdu pociągu pomiędzy stacjami $t$:
\[
    u=\frac{s}{t}.
\]
W takim samym czasie uczeń pokonuje długość całego pociągu $l$ ze średnią szybkością $v_{p}$ względem pociągu:
\[
    v_{p}=\frac{l}{t}, \qquad t=\frac{l}{v_{p}}.
\]
W ten sposób otrzymujemy ostateczne wyrażenie na szybkość pociągu względem peronu:
\[
    u=\frac{s \cdot v_{p}}{l}.
\]
)sofi";
  pV.push_back(text);

// Wskazówka
text = R"sofi(Z  transformacji Galileusza wynika zależność:
\[
    v_{z}=u-v_{p}.
\])sofi";
pV.push_back(text);


// Odpowiedź
  text = "Pociąg jechał ze  średnią szybkością ";
  text += s(u,2);
  text += R"sofi( $\frac{\text{km}}{\text{h}}$, uczeń względem ziemi poruszał się ze średnią  szybkością )sofi";
  text += s(v_z,2);
  text += R"sofi( $\frac{\text{km}}{\text{h}}$.)sofi";

  pV.push_back(text);

  return pV;
  
 } // End of lambda expression
 ); // End of addProblem

//--------------------------------------------------------------------------

//Naładowane kule
addProblem 
("pl-elektrostatyka-0000200", // ID (string)
 "Naładowane kule", // Title (string)
 "Zofia Drabek", // Authors (string)
 "2018-05-25", // Date of the last update (string)
 1, // Difficulty (int)
 []{ // Lambda expression (returns vector<string>)
     
  //zmienne
  int q_1 = r({-3,-2,-1,1,2,3}); // ładunek pierwszej kuli
  int q_2 = r({-3,-2,-1,1,2,3}); // ładunek drugiej kuli
  int d = r({30,50,25,40,200,300,400}); // odległość po rozsunięciu [:100] 
  int qq = q_1*q_2; // iloczyn ładunków
  double f = (double)1000000/pow(itod(d),2); // stosunek sił [:100]
  int f_i = dtoi(f*100);
  string l,p;
  if(qq<0){
    l = "w prawo/\\st{ wlewo}";
    p = "\\st{w prawo}/w lewo";
  }else{
    p = "w prawo/\\st{w lewo}";
    l = "\\st{w prawo}/w lewo";   
  }
  string qq_s = abs(qq) != 1 ? s(abs(qq)) : "" ;
  string F_p = R"sofi(
  \[
      F=k\frac{)sofi" + qq_s + R"sofi(q^{2}}{d^{2}}
  \])sofi";
  string F_k = R"sofi(
  \[
      F=k\frac{)sofi" + qq_s + R"sofi(q^{2}}{()sofi" + s(d,2) + R"sofi(d)^{2}}
  \])sofi";


  string F_p_in = R"sofi(
  \[
      \phantom{F=k\frac{)sofi" + s(abs(qq)) + R"sofi(q^{2}}{d^{2}}}
  \])sofi";

  string F_k_in = R"sofi(
  \[
      \phantom{F=k\frac{)sofi" + s(abs(qq)) + R"sofi(q^{2}}{()sofi" + s(d,2) + R"sofi(d)^{2}}}
  \])sofi";
  string move_1, move_2;
  if(d<100){
    move_1 = "przed zsunięciem";
    move_2 = "po zsunięciu";
  } else{
    move_1 = "przed rozsunięciem";
    move_2 = "po rozsunięciu";
  }


  string text = R"sofi(Powierzchnie dwóch jednakowych plastikowych kul naładowano jednorodnie: pierwszej kuli ładunkiem $)sofi";
  switch(q_1){
    case -1:
    text +=  "-q";
    break;
    case 1:
    text +=  "+q";
    break;
    default:
    text += s(q_1);
    text += " q";
    break;
  }
  text += R"sofi($, a drugiej ładunkiem $)sofi";
  switch(q_2){
    case -1:
    text +=  "-q";
    break;
    case 1:
    text +=  "+q";
    break;
    default:
    text += s(q_2);
    text += "q";
    break;
}
text += R"sofi($. Środki kul na początku były w odległości $d$ od siebie, następnie przemieszczono jedną z kul i ta odległość wynosiła $)sofi";
text += s(d,2);
text += R"sofi(d$.\\
a) Uzupelnij luki i skreśl wyrazy tak, aby tabela zawierała prawdziwe informacje o siłach działajacych na kule przedstawione na rysunku.


\begin{center}
  \begin{asy}[width=0.70\textwidth]

import geometry;

int d = 5;
pair C_1=(12,0);
pair C_2=(-12,0);
real r;

draw(circle(C_1,d), linewidth(0.2));
draw(circle(C_2,d), linewidth(0.2));
  \end{asy}
\end{center}


\begin{table}[h]
\centering
\newcolumntype{Y}{>{\centering\arraybackslash}X}

\begin{tabularx}{\textwidth}{ Y|Y|Y|Y }
\hline
\multicolumn{2}{c|}{kula $1$} & \multicolumn{2}{c}{kula $2$}  \\ \hline
\multicolumn{4}{c}{)sofi"+ move_1 +R"sofi(} \\ \hline
zwrot siły działającej na kulę 1: & w prawo/w lewo & zwrot siły działającej na kulę 2: & w prawo/w lewo \\ \hline
wyrażenie opisujące wartość tej siły: & )sofi" + F_p_in + R"sofi( &  wyrażenie opisujące wartość tej siły: & )sofi" + F_p_in + R"sofi( \\ \hline
\multicolumn{4}{c}{)sofi"+ move_2 +R"sofi(} \\ \hline
zwrot siły działającej na kulę 1: & w prawo/w lewo & zwrot siły działającej na kulę 2: & w prawo/w lewo \\ \hline
wyrażenie opisujące wartość tej siły: & )sofi" + F_k_in + R"sofi( &  wyrażenie opisujące wartość tej siły: & )sofi" + F_k_in + R"sofi( \\
\end{tabularx}

\end{table}

b) Oblicz stosunek wartości siły działającej )sofi" + move_2 + R"sofi( do tej, która działała na początku.
)sofi";



  vector<string> pV;
  pV.push_back(text);
 
  // Wskazówka
  text = "Aby ustalić zwrot siły, zwróć uwagę na znaki ładunków.";
  pV.push_back(text);

  // Wskazówka
  text = R"sofi(Wartość działającej siły jest taka sama dla obu kul (III zasada dynamiki Newtona). Można ją obliczyć za pomocą  zależności wynikającej z prawa Coulomba:
  \[
      F=k\frac{q_{1}q_{2}}{d^{2}},
  \]
  gdzie  $q_{1}$ i $q_{2}$ są wartościami ładunków odpowiednio na kuli $1$ i na kuli $2$, $d$ to odległość między kulami, a $k$ to stała elektryczna.)sofi";
  pV.push_back(text);


  // Wskazówka
  text = "Aby obliczyć stosunek sił, należy podzielić przez siebie wyznaczone już wartości.";
  pV.push_back(text);

 
  // Odpowiedź
  text = R"sofi(
  a) \\
  \begin{center}
  \begin{asy}[width=0.70\textwidth]

import geometry;

int d = 5;
pair C_1=(12,0);
pair C_2=(-12,0);
real r;

draw(circle(C_1,d), linewidth(0.2));
draw(circle(C_2,d), linewidth(0.2));
  \end{asy}
\end{center}

\begin{table}[h]
\centering
\newcolumntype{Y}{>{\centering\arraybackslash}X}

\begin{tabularx}{\textwidth}{ Y|Y|Y|Y }
\hline
\multicolumn{2}{c|}{kula $1$} & \multicolumn{2}{c}{kula $2$}  \\ \hline
\multicolumn{4}{c}{)sofi"+ move_1 +R"sofi(} \\ \hline
zwrot siły działającej na kulę 1: & )sofi"+ l +R"sofi( & zwrot siły działającej na kulę 2: &)sofi"+ p +R"sofi( \\ \hline
wyrażenie opisujące wartość tej siły: & )sofi" + F_p + R"sofi( &  wyrażenie opisujące wartość tej siły: & )sofi" + F_p + R"sofi( \\ \hline
\multicolumn{4}{c}{)sofi"+ move_2 +R"sofi(} \\ \hline
zwrot siły działającej na kulę 1: & )sofi"+ l +R"sofi( & zwrot siły działającej na kulę 2: & )sofi"+ p +R"sofi( \\ \hline
wyrażenie opisujące wartość tej siły: & )sofi" + F_k + R"sofi( &  wyrażenie opisujące wartość tej siły: & )sofi" + F_k + R"sofi( \\
\end{tabularx}

\end{table}

b) Stosunek sił wynosi $\frac{1}{()sofi" + s(d,2) +R"sofi()^{2}} \approx )sofi";
    text += s(o(f_i,3),4);  
    text +="$.";
  
    pV.push_back(text);
  
    return pV;
    
   } // End of lambda expression
   ); // End of addProblem
  
  //--------------------------------------------------------------------------
  // W ile sekund do setki?
  addProblem 
  ("pl-prędkość-droga-czas-0000500", // ID (string)
   "W ile sekund do setki?", // Title (string)"
 "Zofia Drabek", // Authors (string)
 "2018-05-23", // Date of the last update (string)
 2, // Difficulty (int)
 []{ // Lambda expression (returns vector<string>)
     
  //zmienne
  int v = r(10,20); // szybkość  po 1s [km/h]
  double s_1 = itod(v)/7.2; // droga przejechana w 1s ruchu [m]
  double s_2 = s_1*3; // droga przejechana w 2s ruchu [m]
  double s_5 = s_1*9; // droga przejechana w 5s ruchu [m]
  double t = 100./itod(v);

  string text = "Samochód, ruszając z miejsca ruchem jednostajnie przyspieszonym po linii prostej, osiągnął po pierwszej sekundzie ruchu szybkość $";
  text += s(v);
  text += "$ $\\frac{\\text{km}}{\\text{h}}$. \\ Jaką drogę  przebędzie ten samochód w drugiej sekundzie ruchu, a jaką w piątej? Ile czasu potrzebuje ten samochód, aby rozpędzić się do $100$~$\\frac{\\text{km}}{\\text{h}}$?";

  vector<string> pV;
  pV.push_back(text);
 
  // Wskazówka
  text = "Zastanów się, jaką drogę przebędzie ten samochód w pierwszej sekundzie ruchu.";
  pV.push_back(text);

    // Wskazówka
  text = R"sofi(Drogę w ruchu jednostajnie przyspieszonym bez prędkości początkowej obliczamy ze wzoru:
  \[
    s = \frac{at^{2}}{2},
  \]
  gdzie $a$ jest przyspieszeniem, a $t$ czasem. Przyspieszenie obliczymy z zależności:
  \[
    a=\frac{\Delta v}{\Delta t}.
  \]
  )sofi";
  pV.push_back(text);

   // Wskazówka
  text = R"sofi(Zauważ, że w ruchu jednostajnie przyspieszonym długości przebytej drogi w kolejnych równych odstępach czasu są do siebie w stosunku takim jak kolejne liczby nieparzyste. W takim razie prawdziwe są zależności:
  \[
    s_{2} = 3 \cdot s_{1}, \qquad  s_{5} = 9 \cdot s_{1},
  \]
  gdzie $s_{1}$, $s_{2}$ i $s_{5}$ oznaczają odpowiednio drogę przebytą w 1, 2 i 5 sekundzie ruchu.
  )sofi";
  pV.push_back(text);
 
  // Wskazówka
  text = R"sofi(Aby obliczyć, jak szybko samochód osiągnie $100$~$\frac{\text{km}}{\text{h}}$, należy przekształcić wzór na szybkość w ruchu jednostajnie przyspieszonym:
  \[
    v=at, \qquad t=\frac{v}{a}.
  \]
  Należy przyjąć $v=100$ $\frac{\text{km}}{\text{h}}$.
  )sofi";
  pV.push_back(text);

  // Odpowiedź
  text = R"sofi(W drugiej sekundzie ruchu samochód przejechał około $)sofi";
  text += s(o(dtoi(s_2*100),3),2);
  text += R"sofi($ m, a w piątej $)sofi";
  text += s(o(dtoi(s_5*100),3),2);
  text += R"sofi($ m. Natomiast do setki samochód rozpędzi się w $)sofi";
  text += s(o(dtoi(t*100),3),2);
  text += "$ s.";

  pV.push_back(text);

  return pV;
  
 } // End of lambda expression
 ); // End of addProblem


//--------------------------------------------------------------------------

//Która to ciecz?
addProblem 
("pl-hydrostatyka-0000100", // ID (string)
 "Która to ciecz?", // Title (string)
 "Zofia Drabek", // Authors (string)
 "2018-05-24", // Date of the last update (string)
 2, // Difficulty (int)
 []{ // Lambda expression (returns vector<string>)
     
  //zmienne 
  vector<pair <string, int> > t_density;
  t_density.push_back(make_pair(" gliceryna",1260));
  t_density.push_back(make_pair(" woda",1000));
  t_density.push_back(make_pair(" etanol",785));
  unsigned int ver_A = (unsigned) r(0,2); // wybór substancji A
  unsigned int ver_B = (unsigned) r({ ((int)ver_A + 2) % 3, ((int)ver_A + 1) % 3}); // wybór substancji B
  int ro_A = t_density.at(ver_A).second;
  int ro_B = t_density.at(ver_B).second;

  vector<int> t_force_A; // [N :100000]
  vector<int> t_force_B; // [N :100000]
  for(int i=0; i<3; i++){
    int oscilation = r({-200,-100,0,100,200});
    t_force_A.push_back(o(ro_A*(i+2)+oscilation,2));
    oscilation = r({-200,-100,0,100,200});
    t_force_B.push_back(o(ro_B*(i+2)+oscilation,2));
  }
  string wykres_1,wykres_2;
  if(ver_A < ver_B){
    wykres_1 = "A";
    wykres_2 = "B";
  }else{
    wykres_1 = "B";
    wykres_2 = "A";
  }

  string text = R"sofi(Prostopadłościan wykonany z porcelany zawieszono na siłomierzu i zmierzono jego ciężar $Q$. Następnie zanurzano prostopadłościan w cieczy A, a później w cieczy B. Notowano przy tym wartości wskazywane przez siłomierz oraz objętość zanurzonej części prostopadłościanu.
  Poniższa tabela przedstawia wyniki pomiarów.
  \begin{center}
  \begin{tabular}{c|c|c|c}
  siła  ciężkości $Q$ [N] & odczyt z siłomierza [N] & siła wyporu $F_{w}$ [N] & objętość zanurzenia $V_z$ [cm$^{3}$] \\ \hline
    \multicolumn{4}{c}{substancja A} 
  )sofi";
  for(vector<unsigned int>::size_type i=0; i<3; i++){
    text +=  R"sofi( 
    \\ \hline 
    0,100 & )sofi" + s((10000 - t_force_A[i]) / 100, 3, "keepZeros") + " & " + s(t_force_A[i] / 100, 3, "keepZeros")  + " & " + s((int)i+2) ;
  }
  text += R"sofi( \\ \hline
  \multicolumn{4}{c}{substancja B})sofi";
  for(vector<unsigned int>::size_type i=0; i<3; i++){
    text +=  R"sofi( 
    \\ \hline 
    0,100 & )sofi" + s((10000 - t_force_B[i]) / 100, 3, "keepZeros") + " & " + s(t_force_B[i] / 100, 3, "keepZeros")  + " & " + s((int)i+2) ;
  }
  text += R"sofi(
  \end{tabular}
  \end{center}
  
  \begin{enumerate}[a)]
  \item Poniżej przedstawiono wykresy zależności siły wyporu $F_{w}$ od objętości zanurzenia $V_{z}$ dla dwóch cieczy. Podpisz odpowiednio: ,,substancja A'', ,,substancja B''. 
  
  \begin{center}
  \begin{asy}[width=0.5\textwidth]
import graph;

unitsize(x=0.1cm);
real f(real x){return 2*x;}
real g(real x){return 0.75*x;}
xlimits( 0, 30);
ylimits( 0, 30);
draw( graph(f,0,30), blue+linewidth(1));
draw( graph(g,0,40), red+linewidth(1));
xaxis(Label("$V_{z}$",position=EndPoint, align=SE),Ticks("%",extend=true), Arrow);
yaxis(Label("$F_{w}$",position=EndPoint, align=NW),Ticks("%",extend=true), Arrow);

labelx("$(0,0)$",0,SE);
label("substancja \phantom{A}",(15,f(15)),19N);
label("substancja \phantom{B}",(15,g(15)),5E);
  \end{asy}
\end{center}

    \item Która z wymienionych niżej cieczy mogłaby być substancją A, a która substancją B? Przyjmij, że przyspieszenie ziemskie wynosi $g=10\frac{\text{m}}{\text{s}^{2}}$.

  
  \begin{center}
  \begin{tabular}{c|c}
  ciecz & gęstość [$\frac{\text{kg}}{\text{m}^3}$]
  )sofi";
  for(vector<unsigned int>::size_type i=0; i<3; i++){
    text += + R"sofi( \\ \hline )sofi" + t_density[i].first + " & " + s(t_density[i].second) ;
  }
  text += R"sofi(
  \end{tabular}
  \end{center}


  \item Jakie prawo opisuje badane tutaj zjawisko? Opisz je.
  \end{enumerate}
    )sofi";

  vector<string> pV;
  pV.push_back(text);
 
  // Wskazówka
  text = R"sofi(
  \begin{enumerate}[a)]
  \item Która substancja działa większą siłą wyporu dla takiej samej objętości zanurzenia? Jaki ma to związek z gęstością cieczy?
  \end{enumerate}
  )sofi";
  pV.push_back(text);
 
  // Wskazówka
  text = R"sofi(
  \begin{enumerate}[b)]
  \item Siła  wyporu zależy w następujący sposób od gęstości:
    \[
      F_{w} = \rho_{c} g V_{z},
    \]
    gdzie $\rho_{c}$ oznacza  gęstość cieczy, a $g$ przyspieszenie ziemskie. Zatem gęstość  obliczymy z zależności:
    \[
        \rho_{c} = \frac{F_{w}}{g V_{z}}.
    \]
    Pamiętaj że obliczona gęstość może nie być dokładnie taka, jak w tabelce, ze względu na niepewności pomiarowe. Ze względu na nie obliczenia najlepiej jest wykonać dla największego podanego $V_{z}$, wtedy względna niepewność jest najmniejsza.
  \end{enumerate}
  )sofi";
  pV.push_back(text);


  // Odpowiedź
  text = R"sofi(
  \begin{enumerate}[a)]
  \item ~\\

  \begin{center}
  \begin{asy}[width=0.5\textwidth]
import graph;

unitsize(x=0.1cm);
real f(real x){return 2*x;}
real g(real x){return 0.75*x;}
xlimits( 0, 30);
ylimits( 0, 30);
draw(graph(f,0,30),blue+linewidth(1));
draw(graph(g,0,40),red+linewidth(1));
xaxis(Label("$V_{z}$",position=EndPoint, align=SE),Ticks("%",extend=true), Arrow);
yaxis(Label("$F_{w}$",position=EndPoint, align=NW),Ticks("%",extend=true), Arrow);

labelx("$(0,0)$",0,SE);
label("substancja )sofi" + wykres_1 + R"sofi(",(15,f(15)),19N);
label("substancja )sofi" + wykres_2 + R"sofi(",(15,g(15)),5E);
  \end{asy}
\end{center}

  \item Substancją A )sofi";

  if(ver_A == 0){
    text += "mogłaby być gliceryna,";
  }else if(ver_A == 1){
    text += "mogłaby być woda,";
  }else{
    text += "mógłby być etanol,";
  }
  text += R"sofi( a substancją B )sofi" + t_density.at(ver_B).first + ".";
  text += R"sofi(
  \item Badane zjawisko jest opisywane przez prawo Archimedesa. Mówi ono, że na ciało zanurzone w cieczy działa siła skierowana pionowo ku górze równa ciążarowi wypartej cieczy. Opisana jest wspomnianym już wzorem  $F_{w} = \rho_{c} g V_{z}$.
  \end{enumerate} 
  )sofi";

  pV.push_back(text);

  return pV;

 } // End of lambda expression
 ); // End of addProblem


//--------------------------------------------------------------------------
//Wyrzutnia piłek do tenisa
addProblem 
("pl-mechanika-0000500", // ID (string)
 "Wyrzutnia piłek do tenisa", // Title (string)
 "Zofia Drabek", // Authors (string)
 "2018-05-26", // Date of the last update (string)
 3, // Difficulty (int)
 []{ // Lambda expression (returns vector<string>)
     
  //zmienne
  int m = r(56,59); // masa [g]
  int v = r(50,130); // prędkość [km/h]
  int t = r(2,4); //czas [s :10]
  int g = 10;
  int mg_eff = o(dtoi(m*g/sqrt(2.0)),2); // [N] :1000
  double F = itod(v)*m/(360*t) + itod(mg_eff)/1000; // [N]
  double P = F*v*5/36; // [W]

  string text = R"sofi(Wyrzutnia, składająca się z lufy, w ktorej porusza się tłok, wyrzuca piłki o masie $)sofi";
  text += s(m);
  text += R"sofi($ g z~szybkością $)sofi";
  text += s(v);
  text += R"sofi($ $\frac{\text{km}}{\text{h}}$. Mechanizm wyrzucający działa tak, że przez cały czas, gdy piłka jest w~kontakcie z~wyrzutnią, poruszający się tłok działa na piłkę stałą siłą i trwa to $)sofi";
  text += s(t,1);
  text += R"sofi($ s. Wiadomo, że przed uruchomieniem wyrzutni spoczywająca piłka działa na tłok siłą $R = )sofi";
  text += s(mg_eff,3);
  text += R"sofi($ N.  
  \begin{enumerate}[a)]
  \item Jaką siłą działa poruszający się tłok na piłkę?
  \item Oblicz średnią moc, z jaką wyrzutnia wyrzuca piłki.
  \end{enumerate}
  Przyjmij, że przyspieszenie ziemskie wynosi $g = 10 \frac{\text{m}}{\text{s}^{2}}$.
  )sofi";

  vector<string> pV;
  pV.push_back(text);
 
  // Wskazówka
  text = R"sofi(a) Siła $F$, z jaką tłok dział na piłkę, przeciwdziała sile $R$ oraz powoduje przyrost pędu $\Delta p$ w czasie $\Delta t$. Z czego wynikają poniższe zależności:
  \[
    F = \frac{\Delta p}{\Delta t} + R = \frac{\Delta v \cdot m}{\Delta t} + R ,
  \]
  gdzie $\Delta v$ jest przyrostem prędkości, a $m$ masą piłki. Piłki początkowo spoczywają, więc przyrost prędkości jest równy prędkości, jaką piłka osiąga po rozpędzeniu przez tłok.
  )sofi";
  pV.push_back(text);
  
  // Wskazówka
  text = R"sofi( b) Korzystamy z tego, że wartość siły była stała. Średnią moc $P$ możemy obliczyć z zależności:
  \[
    	P = \frac{W}{\Delta t} = \frac{F s}{\Delta t},  
  \] 
  \[
  	 	s = \frac{a (\Delta t)^{2}}{2}.
  \]
  gdzie $W$ oznacza pracę, a $a$ to przyspieszenie równe $\frac{\Delta v}{\Delta t}$. A więc:
  \[
  	  P = \frac{F \Delta v}{2}.
  \]

  )sofi";
  pV.push_back(text);

  // Odpowiedź
  text = R"sofi(a) Poruszający się tłok działa na piłkę siłą ok. $)sofi";
  text += s(o(dtoi(F*10000),3),4);
  text += R"sofi($ N. \\)sofi";
  text += R"sofi(b) Piłki wyrzucane są ze średnią mocą ok. $)sofi";
  text += s(o(dtoi(P*10000),3),4);
  text += R"sofi($ W.)sofi";
  pV.push_back(text);

  return pV;
  
 } // End of lambda expression
 ); // End of addProblem



//--------------------------------------------------------------------------
//Gdzie ta soczewka?
addProblem 
("pl-optyka-0000200", // ID (string)
 "Gdzie ta soczewka?", // Title (string)
 "Zofia Drabek", // Authors (string)
 "2018-05-31", // Date of the last update (string)
 1, // Difficulty (int)
 []{ // Lambda expression (returns vector<string>)
     
  //zmienne
  int ver = r(0,3);
  int a; //wielkość przedmiotu
  int a_p; //wielkość obrazu
  string answer;
  string answer_1;
  string position_0, position_1;
  string promien = (ver == 0 || ver == 1) ? "" : ", dashed";
  switch( ver ){
    case 0:
      a = 80;
      a_p = -40;
      answer = "pomniejszony, odwrócony i rzeczywisty.";
      answer_1 = "skupiająca";
      position_0 = "N";
      position_1 = "S";
      break;
    case 1:
      a = 40;
      a_p = -80;
      answer = "powiększony, odwrócony i rzeczywisty.";
      answer_1 = "skupiająca";
      position_0 = "N";
      position_1 = "S";
      break;
    case 2:
      a = 80;
      a_p = 40;
      answer = "pomniejszony, prosty i pozorny.";
      answer_1 = "rozpraszająca";
      position_0 = "S";
      position_1 = "N";
      break;
    case 3:
      a = 40;
      a_p = 80;
      answer = "powiększony, prosty i pozorny.";
      answer_1 = "skupiająca";
      position_0 = "S";
      position_1 = "N";
      break;
    default:
      a = 0;
      a_p = 0;
      answer = "";
      answer_1 = "";
      position_0 = "";
      position_1 = "";
      break;
  }
       
  string text = R"sofi(Poniższy rysunek przedstawia w  schematyczny sposób przedmiot AB oraz obraz A'B' powstały po przejściu przez cienką soczewkę światła emitowanego przez przedmiot AB. Zaznaczono też oś optyczną BB'. Wypisz 3 cechy obrazu. Znajdź położenie soczewki oraz rozstrzygnij, czy użyto soczewki skupiającej, czy rozpraszającej.

    \begin{center}
  \begin{asy}[width=1\textwidth]
    import geometry;

    real a = )sofi" + s(a) + R"sofi(;
    real a_p = -()sofi" + s(a_p) + R"sofi();
    real k = 2;

    pair A = ((-1)*a*k,a); // przedmiot
    pair B = (A.x,0); // przedmiot
    pair A_p = (a_p*k,(-1)*a_p); //obraz
    pair B_p = (A_p.x,0); //obraz
    //oś opyczna 
    pair L_1 = (-170,0);
    pair L_2 = (170,0);

    draw(B--A, Arrow);
    draw(B_p--A_p, Arrow);
    draw(L_1--L_2, dashed);
  
    label( "A", A, 2N);
    label( "B", B, 2S);
    label( "A'", A_p, 2)sofi" + position_1 + R"sofi();
    label( "B'", B_p, 2)sofi" + position_0 + R"sofi();

  \end{asy}
\end{center}
  )sofi";
  vector<string> pV;
  pV.push_back(text);
 
  // Wskazówka
  text = R"sofi(Zastanów się, czy obraz jest większy, czy mniejszy od przedmiotu. Czy obraz jest odwrócony? Czy obraz powstaje przez przecięcie promieni, czy ich przedłużeń?
  )sofi";
  pV.push_back(text);
   // Wskazówka
  text = R"sofi(
  Aby znaleźć soczewkę, wystarczy narysować prostą AA'. Przecięcie tej prostej z osią optyczną wskazuje położenie soczewki. Jest ona ułożona prostopadle do osi optycznej.
  )sofi";
  pV.push_back(text);

    // Wskazówka
  text = R"sofi(
    Aby rozstrzygnąć, czy jest to soczewka skupiająca, czy rozpraszająca, dobrze jest sprawdzić, w  jaki  sposób zachowa się  promień padający na soczewkę równolegle do osi optycznej.
  )sofi";
  pV.push_back(text);
  // Odpowiedź
  text = "Obraz jest " + answer;
  text += R"sofi(
      \begin{center}
  \begin{asy}[width=1\textwidth]
    import geometry;

    void drawV(pair start, pair direction, real angle, real  length, real widthOfLine) {
      pair end1 = start + length * direction * expi(+radians( angle));
      pair end2 = start + length * direction * expi(-radians(angle));
      draw(start--end1, linewidth(widthOfLine));
      draw(start--end2, linewidth(widthOfLine));
    }

    real a = )sofi" + s(a) + R"sofi(;
    real a_p = -()sofi" + s(a_p) + R"sofi();
    real k = 2;

    pair O = (0,0); // położenie soczewki
    pair A = ((-1)*a*k,a); // przedmiot
    pair B = (A.x,0); // przedmiot
    pair A_p = (a_p*k,(-1)*a_p); //obraz
    pair B_p = (A_p.x,0); //obraz
    // oś optyczna
    pair L_1 = (-170,0);
    pair L_2 = (170,0);

    // przedmioty
    draw(B--A, Arrow);
    draw(B_p--A_p, Arrow);
    draw(L_1--L_2, dashed);
    dot(O);

    // soczewka
    path soczewki = (0,100)--(0,-100);
    draw(soczewki, linewidth(1.5));
    real kat = )sofi";
    text += ver !=2? "35":"145";
    text += R"sofi(; 
    drawV((0,100),+dir(soczewki),kat,10,1.5);
    drawV((0,-100),-dir(soczewki),kat,10,1.5);

    //promienie
    draw(A--O);
    draw(A--(0,A.y));
    draw(O--A_p)sofi" + promien + R"sofi();
    draw((0,A.y)--A_p)sofi" + promien + R"sofi();

    label( "A", A, 2N);
    label( "B", B, 2S);
    label( "A'", A_p, 2)sofi" + position_1 + R"sofi();
    label( "B'", B_p, 2)sofi" + position_0 + R"sofi();

  \end{asy}
\end{center}
Soczewka jest )sofi";
  text += answer_1;
  text += ".";


  pV.push_back(text);

  return pV;
  
 } // End of lambda expression
 ); // End of addProblem

//--------------------------------------------------------------------------

//Opór zastępczy
addProblem 
("pl-prąd-0000900", // ID (string)
 "Opór zastępczy", // Title (string)
 "Zofia Drabek", // Authors (string)
 "2018-05-31", // Date of the last update (string)
 2, // Difficulty (int)
 []{ // Lambda expression (returns vector<string>)
     
  //zmienne

  int U = r(1,5); // napięcie [V]
  int R = 4*r(1,6); // opór [om]
  int R_z = 3*R/4; // opór zastępczy [om]
  double I_AC = itod(U)/R; //natężenie [A]
  double I_ABC = itod(U)/(3*R);//natężenie [A]
  double U_BC = I_ABC*R; // napięcie między B i C [V]
       
  string text = "Cztery oporniki o takich samych oporach $R = ";
  text += s(R);
  text += "$ $\\Omega$ połączono w sposób przedstawiony na rysunku. Napięcie $U$ między punktami A  i C wynosi $";
  text += s(U);
  text += " $ V.";
  text += R"sofi(
  \begin{enumerate}[a)]
  		\item Oblicz opór zastępczy między zaciskami A i C.
   		\item Oblicz natężenia prądów $I_{1}$, $I_{2}$ i $I_{3}$ zaznaczonych na rysunku.
   		\item Oblicz spadek napięcia między punktami B i C.
  \end{enumerate}

  \begin{center}
  \begin{asy}[width=0.5\textwidth]
  import geometry;

pair C = 200*dir(90);
pair B = 200*dir(-30);
pair A = 200*dir(210);

dot(A);
dot(B);
dot(C);

int d = 20;
int l = 30;

// opornik wzorzec
pair X_1 = ( -l, A.y-d);
pair X_2 = ( l, A.y-d);
pair X_3 = ( l, A.y+d);
pair X_4 = ( -l, A.y+d);


// draw(X_1--X_2--X_3--X_4--X_1, linewidth(1.5));


draw(X_1+(l+10,0)--X_2+(l+10,0)--X_3+(l+10,0)--X_4+(l+10,0)--X_1+(l+10,0), linewidth(1.5));

draw(X_1-(l+10,0)--X_2-(l+10,0)--X_3-(l+10,0)--X_4-(l+10,0)--X_1-(l+10,0), linewidth(1.5));

draw(rotate(120)*X_1--rotate(120)*X_2--rotate(120)*X_3--rotate(120)*X_4--rotate(120)*X_1, linewidth(1.5));

draw(rotate(-120)*X_1--rotate(-120)*X_2--rotate(-120)*X_3--rotate(-120)*X_4--rotate(-120)*X_1, linewidth(1.5));


pair X = (-l, A.y);
pair Y = (l, A.y);

draw(A--(-2*l-10, A.y));
draw((-10, A.y)--(10, A.y));
draw((2*l+10, A.y)--B);

draw(rotate(120)*A--rotate(120)*(-l, A.y));
draw(rotate(120)*(l, A.y)--rotate(120)*B);

draw(rotate(-120)*A--rotate(-120)*(-l, A.y));
draw(rotate(-120)*(l, A.y)--rotate(-120)*B);

label( "A", A, W);
label( "B", B, E);
label( "C", C, N);

path I_1 = (A.x*(2/3)-30,B.y)--(A.x*(2/3),B.y); 
draw(Label("$I_{1}$"), I_1, Arrow);

path I_2 = rotate(120)*((A.x*(2/3)-30,B.y)--(A.x*(2/3),B.y)); 
draw(Label("$I_{2}$"), I_2, Arrow);

path I_3 = rotate(-120)*((B.x*(2/3)+30,B.y)--(B.x*(2/3),B.y)); 
draw(Label("$I_{3}$"), I_3, Arrow);

  \end{asy}
\end{center}
  )sofi";

  vector<string> pV;
  pV.push_back(text);
 
  // Wskazówka
  text = "a) Zastanów się, w jaki sposób połączone są oporniki. Spróbuj narysować ten układ w prostszy sposób.";
  pV.push_back(text);
 
  // Wskazówka
  text = R"sofi( Gdy rozrysujemy podany układ w postaci, w której będzie bardziej przejrzysty, otrzymamy dwie gałęzie połączone równolegle. W pierwszej znajdzie się jeden opornik, a w drugiej trzy oporniki połączone szeregowo. W takim razie opór zastępczy w pierwszej gałęzi wynosi $R$, a w drugiej $3R$. Ponieważ opisane fragmenty obwodu połączone są równolegle, to opór zastępczy obliczymy w  następujący sposób:
  \[
  		\frac{1}{R_{z}} = \frac{1}{R} + \frac{1}{3R},
  \]
  \[
  		R_{z} = \frac{3R}{4}.
  \]

   )sofi";
  pV.push_back(text);

  // Wskazówka
  text = R"sofi(
  b) Do obliczenia natężenia można wykorzystać wzór
  \[
    I=\frac{U}{R}.
  \]
  Należy go zastosować dla każdej gałęzi opisanej w poprzedniej wskazówce oddzielnie. Zwróć uwagę,  że $I_{1}=I_{2}$.
  )sofi";
  pV.push_back(text);
 
  // Wskazówka
  text = "c) Napięcie obliczymy z zależności  $U_{BC} = I_{2} R$.";
  pV.push_back(text);
 
  // Odpowiedź
  text = R"sofi(
  \begin{enumerate}[a)]
  \item Opór zastępczy takiego ukladu wynosi $)sofi";
  text += s(R_z);
  text += R"sofi($ $\Omega$.
  \item Natężenia poszczególnych prądów wynoszą $I_{1}=I_{2}=)sofi";
  text += s(o(dtoi(I_ABC*10000),3),1);
  text += "$ mA, a $I_{3}=";
  text += s(o(dtoi(I_AC*10000),3),1);
  text += R"sofi($ mA.
  \item Spadek napięcia między punktami B i C  wynosi )sofi";
  text += s( o(dtoi(U_BC*10000),  3), 4);
  text +=  R"sofi( V.
  \end{enumerate})sofi";

  pV.push_back(text);

  return pV;
  
 } // End of lambda expression
 ); // End of addProblem

//--------------------------------------------------------------------------
//Generator fal
addProblem 
("pl-fale-0000300", // ID (string)
 "Generator fal", // Title (string)
 "Zofia Drabek", // Authors (string)
 "2018-06-1", // Date of the last update (string)
 1, // Difficulty (int)
 []{ // Lambda expression (returns vector<string>)
     
  //zmienne
  int T = r(10,35); // [s] :100
  int v = o(16*T,2); // [m/s] :1000
  double f = 100.0/itod(T); // [Hz]
  double l = itod(T)*v; // [m] :100000
  

  string text = "Uczeń nalał wody do wanny. Na powierzchni wody położył drewnianą listewkę połączoną z generatorem drgań. Generator poruszał listewką pionowo, ze stałą częstotliwością tak, że listewka cały czas była w kontakcie z wodą. W górnym położeniu znajdowała się co $";
  text += s(T,2);
  text += R"sofi( $ s. Uczeń wytworzył w ten sposób na powierzchni wody falę płaską. Jej prędkość wynosi $)sofi";
  text += s(v,3);
  text += R"sofi($ $\frac{\text{m}}{\text{s}}$. Oblicz częstotliwość wytwarzanych fal oraz odległość między kolejnymi grzbietami.)sofi";
  
  vector<string> pV;
  pV.push_back(text);
 
  // Wskazówka
  text = R"sofi(Czas, po jakim listewka znajdzie się ponownie w tym samym położeniu, należy zinterpretować  jako okres $T$. Znajomość okresu umożliwia wyznaczenie częstotliwości $f$: 
  \[
  	  f = \frac{1}{T}.
  \]
  )sofi";
  pV.push_back(text);

  // Wskazówka
  text = R"sofi(Odległość między kolejnymi grzbietami jest równa długości fali $\lambda$ i zależy w następujący sposób od prędkości fali $v$ oraz jej okresu $T$:
  \[
  	  \lambda = T v.
  \]
  )sofi";
  pV.push_back(text);
 
  // Odpowiedź
  text = "Częstotliwość wytwarzanych fal wynosi ok.~$";
  text += s(o(dtoi(f*1000),2),3);
  text += "$ Hz, a odległość między kolejnymi grzbietami fali ok.~$";
  text += s(o(dtoi(l),2),3);
  text += "$ cm.";

  pV.push_back(text);

  return pV;
  
 } // End of lambda expression
 ); // End of addProblem

//--------------------------------------------------------------------------

// Zwojnica
addProblem 
("pl-elektromagnetyzm-0000000", // ID (string)
 "Zwojnica", // Title (string)
 "Zofia Drabek", // Authors (string)
 "2018-06-07", // Date of the last update (string)
 2, // Difficulty (int)
 []{ // Lambda expression (returns vector<string>)
     
  //zmienne
  int ver = r(0,1); // 0(zamknięcie) 1(otworzenie)
  string wlacznik; //zamykanie/otwieranie
  string wlacznik_0; //zamykanie/otwieranie
  string odp_0; // odpowiedź w zal od zamykania/otwierania
  if(ver == 0){
  	wlacznik = "zamknięciu";
  	wlacznik_0 = "zamykamy";
  	odp_0 = "Tuż po zamknięciu obwodu po lewej wzrasta w nim natężenie prądu, co powoduje zmianę pola magnetycznego wokół zwojnicy po lewej, a więc także pola magnetycznego w otoczeniu zwojnicy po prawej. Zajdzie zjawisko indukcji elektromagnetycznej. \\item  Zgodnie z regułą Lenza w obwodzie po prawej popłynie prąd wyindukowany, taki żeby przeciwdziałać przyczynie wywołującej go. Gdy zamykamy obwód, zwiększamy strumień pola elektromagnetycznego wokół zwojnicy, więc prąd w zwojnicy po prawej popłynie w taki sposób, że bieguny elektromagnesu, jakim jest zwojnica, ustawią się przeciwnie niż w zwojnicy po lewej.";
  }else{
  	wlacznik = "otworzeniu zamkniętego";
  	wlacznik_0 = "otwieramy";
  	odp_0 = "Tuż po otworzeniu obwodu po lewej wzrasta w nim natężenie prądu, co powoduje zmianę pola magnetycznego wokół zwojnicy po lewej, a więc także pola magnetycznego w otoczeniu zwojnicy po prawej. Zajdzie zjawisko indukcji elektromagnetycznej. \\item  Zgodnie z regułą Lenza w obwodzie po prawej popłynie prąd wyindukowany, taki żeby przeciwdziałać przyczynie wywołującej go. Gdy otwieramy obwód, zmniejszamy strumień pola elektromagnetycznego wokół zwojnicy, więc prąd w zwojnicy po prawej popłynie w taki sposób, że bieguny elektromagnesu, jakim jest zwojnica, ustawią się tak samo, jak w zwojnicy po lewej.";
  }
  int ver_1 = r(0,1); // 0(takie samo  uzwojenie) 1(odbite uzwojenie)
  int ver_2 = r(0,1); // bateria 0(+-) 1(-+)
  int r = (ver + ver_1 + ver_2) % 2; // kierunek płynącego prądu
  string odp; // kierunek prądu na rysunku
  if(r == 1){
    odp = "draw((1400,-700)--(1400,-350), MidArrow(50));";
  }else{
    odp = "draw((1400,-350)--(1400,-700), MidArrow(50));";
  }
  
  string text = R"sofi(Na schemacie przedstawiono dwie zwojnice. W pierwszym obwodzie znajduje się bateria i włącznik, w drugim amperomierz. Po )sofi";
text += wlacznik;
text += R"sofi( obwodu po lewej w obwodzie po prawej amperomierz zarejestrował przepływ prądu.

\begin{center}
\begin{asy}[width=0.5\textwidth]

//zwoje
path zwoj = (-200,-150){down}..{up}(0,0){up}..{down}(200,150);
path dol = (-200,-150){down}..{up}(0,0);
path gora = (0,0){up}..{down}(200,150);

//zwojnica po lewej
draw(zwoj);
draw(shift(-400)*zwoj);
draw(shift(-800)*gora);
draw(shift(400)*zwoj);
draw(shift(800)*zwoj);

path rdzen = ((-900,150)--(-900,-150)--(1100,-150)--(1100,150)--(-900,150)); // rdzeń zwojnicy
draw(rdzen);

int d =)sofi";
text += ver_2 == 0? "140" : "60"; 
text += R"sofi(; // bateria_+
int h =)sofi";
text += ver_2 == 1? "140" : "60"; 
text += R"sofi( ; // bateria_-
int j = 20; // (1/2) odległości między + i -
int f = 120; // włącznik

path obwod_1 = ((-800,0)--(-800,-900)--(100-j,-900)--(100-j,-900+d)--(100-j,-900-d));
path obwod_2 = ((1000,-150)--(1000,-900)--(500,-900)--(500-2*f,-900+f));
path obwod_3 = ((500-2*f,-900)--(100+j,-900)--(100+j,-900+h)--(100+j,-900-h));

draw(obwod_1);
draw(obwod_2);
draw(obwod_3);
)sofi";

string movement = ver_1 == 0? "shift(2200)": "reflect((1200,10),(1200,-10))";

text += R"sofi(
draw()sofi" + movement + R"sofi(*zwoj);
draw()sofi" + movement + R"sofi(*shift(-400)*zwoj);
draw()sofi" + movement + R"sofi(*shift(-800)*gora);
draw()sofi" + movement + R"sofi(*shift(400)*zwoj);
draw()sofi" + movement + R"sofi(*shift(800)*zwoj);
draw()sofi" + movement + R"sofi(*((-900,150)--(-900,-150)--(1100,-150)--(1100,150)--(-900,150))); // rdzeń zwojnicy

//przewody + amperomierz
draw()sofi" + movement + R"sofi(*((-800,0)--(-800,-900)));
draw()sofi" + movement + R"sofi(*((1000,-900)--(1000,-150)));
draw(shift(2200)*((-800,-900)--(-50,-900)));
draw(shift(2200)*((250,-900)--(1000,-900)));
draw(shift(2200)*circle((100,-900),150));
label("A",shift(2200)*(100,-900));

\end{asy}
\end{center}

  \begin{enumerate}[a)]
  \item Jak wyjaśnisz przepływ prądu w obwodzie po prawej?
  \item Zaznacz na rysunku, w którym kierunku będzie płynął prąd w obwodzie po prawej. Odpowiedź uzasadnij.
  \end{enumerate}
  )sofi";

  vector<string> pV;
  pV.push_back(text);
 
  // Wskazówka
  text = "Gdy " + wlacznik_0 + " obwód, zmieniamy pole magnetyczne wokół zwojnicy. ";
  pV.push_back(text);
  
  // Wskazówka
  text = "Zmiana pola magnetycznego powoduje przepływ prądu w drugiej zwojnicy.";
  pV.push_back(text);
  
  // Wskazówka
  text = "Prąd płynie w taki sposób, aby przeciwdziałać przyczynie, która go wywołała (reguła Lenza).";
  pV.push_back(text);
 
  // Odpowiedź
  text = R"sofi(
  \begin{enumerate}[a)]
  \item )sofi";
  text += odp_0;
  text += R"sofi(
\begin{center}
  \begin{asy}[width=0.5\textwidth]

//zwoje
path zwoj = (-200,-150){down}..{up}(0,0){up}..{down}(200,150);
path dol = (-200,-150){down}..{up}(0,0);
path gora = (0,0){up}..{down}(200,150);

//zwojnica po lewej
draw(zwoj);

draw(shift(-400)*zwoj);

draw(shift(-800)*gora);

draw(shift(400)*zwoj);

draw(shift(800)*zwoj);

path rdzen = ((-900,150)--(-900,-150)--(1100,-150)--(1100,150)--(-900,150)); // rdzeń zwojnicy

draw(rdzen);


int d =)sofi";
text += ver_2 == 0? "140" : "60"; 
text += R"sofi(; // bateria_+
int h =)sofi";
text += ver_2 == 1? "140" : "60"; 
text += R"sofi( ; // bateria_-
int j = 20; // (1/2) odległości między + i -
int f = 120; // włącznik

path obwod_1 = ((-800,0)--(-800,-900)--(100-j,-900)--(100-j,-900+d)--(100-j,-900-d));
path obwod_2 = ((1000,-150)--(1000,-900)--(500,-900)--(500-2*f,-900+f));
path obwod_3 = ((500-2*f,-900)--(100+j,-900)--(100+j,-900+h)--(100+j,-900-h));

draw(obwod_1);
draw(obwod_2);
draw(obwod_3);
)sofi";

movement = ver_1 == 0? "shift(2200)": "reflect((1200,10),(1200,-10))";

text += R"sofi(
draw()sofi" + movement + R"sofi(*zwoj);

draw()sofi" + movement + R"sofi(*shift(-400)*zwoj);

draw()sofi" + movement + R"sofi(*shift(-800)*gora);

draw()sofi" + movement + R"sofi(*shift(400)*zwoj);

draw()sofi" + movement + R"sofi(*shift(800)*zwoj);

draw()sofi" + movement + R"sofi(*((-900,150)--(-900,-150)--(1100,-150)--(1100,150)--(-900,150))); // rdzeń zwojnicy

//przewody + amperomierz
draw()sofi" + movement + R"sofi(*((-800,0)--(-800,-900)));
draw()sofi" + movement + R"sofi(*((1000,-900)--(1000,-150)));
draw(shift(2200)*((-800,-900)--(-50,-900)));
draw(shift(2200)*((250,-900)--(1000,-900)));
draw(shift(2200)*circle((100,-900),150));
label("A",shift(2200)*(100,-900));
)sofi";
text += odp;
text += R"sofi(
  \end{asy}
\end{center}

\end{enumerate}
)sofi";
  text +="";

  pV.push_back(text);

  return pV;
  
 } // End of lambda expression
 ); // End of addProblem
