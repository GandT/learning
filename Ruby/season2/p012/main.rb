# -*- coding: utf-8 -*-
=begin
　2017.5.2
　正規表現
=end


# 照合文字列
# （引用元：http://dic.nicovideo.jp/a/tanasinn）
$String = "                                                                                                                                                      
                 n                                                                                  i                 s                               
                  a                                                                      n                         n                             n    
ss                    n                                         n                                                              a                      
                       n  n          t                                                                        a     a   i                             
                 n                         n                          n                           t       n                                           
                                                        n           i                             a                         n      a                  
                                      n                s        s nn                     n         n             n                                    
                        s           i   tn  t   a     i           a                    i       s                               a   a                  
  i                        i     ast    as      i a   s                             a                 a  a n   ni           aa                 n      
  n   s              i n   n                i         n      a                                  t                     a                             n 
    n                a  n      in           n        n            t n  n                 nt a   t       ni       t      a             nn              
            n sa      s       s              n              s      as a       nn            n        n         t       t                  t   n       
 i          s    s          ns                  aa      a  a  n            a  a        n ns   a         nn        s     a   i     s       n   nn     a
 a        a     s    i       s                   n        n a    nn n  s ns  n n n at  n i           i  a n                      i    a  n         s  
n         n  naa n             n n     t      n         i n   s      a     ti          a              n a    n       a                  a   i    n  s 
         t     t             t a a a  t     t        n    a         s       an           n     n   n   i    tn    a     n                a    ats  s n
 n       ia t a n      in t   n           n  n               an      n      i          n a   n i             t       a   a  a          t     s        
     a  s             n n i   a    n   n        n     n   n            i   i   a    i  n        a    n                    n     t            n a      
        n naa      in    n    ni sn  a    st        n                       a  n    ni n     ss  a n  n          i   a  i  n            a  s   aaa    
a   a a is             t     a            ai                  a     n   t    n    i     n        t   a    n    a   s   n  nan     n           t n   a 
   i sn    n     i   s    s     t   a n   t a a             a t       n         s     n        n   at               i t t a     sn                    
 na    si     s         n          n      s    a    n    s  nn        an      s n   t n   n      i a s     an    nn i   nnn      n i    s         na n
  a t       n    n a     n aa    i  n                      i   at    a   a        a    a    a n          a  t   n      a  in   at            t        
 n   asa  i   sa s  a   n an   t     i st i   a  n      n n n   an             i n          aaa     i    t  s      aa   n   sa ssa  n a  s   nn    a  
 n  tana    n  n                       s   n   ts        at n in n  n        t    s a   i  a  t n    n a       at     n    an      t        n n  a    
     n    i      s   tn  s            ia  n tn     n         ins     t   i     a         santa   tnn  i      i  n     a      a    an nan     sa    t  
 s n    s    ai        ns   n t        i  n       i     i    tan a  n n  n      n     an  ts   s nn    nt   a s  nai   t   aitai s  n     nii    i    
    n  na                     a        na s     nn    t          a nn     i is   a           i   niaa n n                s ai  t        t   a  nan   n
  nt  a     nn i n  nin     n  nn nnn  s     n st  s    t        n   a       n t   ti a  s   i  n    n i  nta     s       n      i  n          n nnn a
  snants  a  n s  t   a    tan nsna          n a    sa n  s    t i n i   t       a   nt   n  ia                   s    s   t       s    n   nn      n 
  a  n sa  a     a  nn   n   iiin    aa     sn t a ana  a     t s   t n ia   n     nn  a  ias   ta    a   n  s n      n  n n i  s n  nsn   t s   a t  
     s  an   t   a   i      t              in  nt  insatn  s  s a     ti   tn  an         ns   nn    tt   s  nn    n aaa  t  s  nan       a           
 nn          a i   i         tnat a    nn     nnn n  n    n s  n   a     n      s      n s i    n         a   n s t      nn a n n  s  n s a           
 s    ai   a  ni       s       n   a  s  n            nn n  at n    ii a  n  s    in  a   t     tsa        s         i   in  n   n ati  s inst an  is 
int s   tt   an nn      a  si  n   n ta     s i    n      nna   a i t     aia    nn  i     a a   n  ana sa t         a aa  n snn  i     ann nt   sn   
  ia  n i ss i nn    s  tt        nn tnts     i i iinnna     t    a  t  i  tt   a n a n  n    a  it   taa nia  nt  n ia n n   in t t tn         n  i n
 saa n  s t   sti nt     n s in      t i      s     t  a  a       n     t aa  n           ta     assa  nn a          a  n   ntan   intnn    i na n  a 
       a     s  an ast    s t  n n  n t  t     n   a  n  n    nn   i aa s    n   n n    s    ii  n a  i   n  t   naann a  t     nn t t   t  n  a a  ia
      tn nt     a  nin s s     at staast n    n sai a nstn    n nit   a  a    a nan na inn n     n a st nn a ti  n as tan n   n t i t a   s  ns  a  a 
 i     nna    n    ta an   a aa      a t t n  an   sn n n    at     n na  tas  t sn n s   nait sniin     n   n ti   n n    i   n a a   s aianan   a n 
s              t  t       ait it   n  nn t   taia a a   n  i  t  a n s n    i  an  n  s i n n   n na  n   nn  a  tn a n  s   a  n ant   sn  nna      t
n n nn       t         an  ta   sataan aia     n a   ntntn ni  a aann ninas          a   n n   an    n    n   ain s iatn  n ts  i  n  a a  nn in     n
     a    s t nn tnnt    n      n   n ti s in   tt n   tn    aa  a inn  t  nas tna t  t n     n    a  si   tin aa n asn t         aint nn    n    i  a
a  nn nnn  t    na   n  n        a      n a t    nnnn    a     in   nias   as    n a  i    n      an  ts t    ts na  s tn  nsants ta sna a n    ttts  
  aai an  n   nnn n  a     t ni  nn n  nn t  a       tnn    s a  san i   tn  a a t  a  sn  t   a n nia i nsn i   nn n   aa na   in  is  s   a   nnn  s
naa n  nnn  s  a  n aan a a  s   a     tn as   aa innns  i  a snsi  a   a ni s s a  n        i    n       i  s    n  nn at tta  s  in i nni t  t sn s 
 iaas ntn  aa    t t i  ani      aa    s n sa n    n ta saa   i     nnns   an ii   nt nnni at a    a nit  s  nn aaa asansnnnn   tn   a  n i nn  ta    
 a     inn   sa ia   nain    ins a s ta  t   tas  an saa  ni i ta        itna n n  a a   nt    ait i   a   n tsnns na   s  n nnni s a     aasaaata  an
   st  nt    an nssn    aa    ii ana n   in  na nin  a  n     sni  aa   a     n    n  n a     tati t   at i s  ntatnaisainin na  ntn n    nn san s nnn
a tnisin     is na a tn   nit nn as     n  ta      an  n   sn  na   n   n a n nn an snnn  a    a n    tna      n tnsnn  a asannnn aa n a  n       ia  
ia t  na n  naasat i s   asinnss nnt    nsann nna  natan   tn  nainn   n nn   n atti an i nantt  s t ataa nsn t   tinn n a n   a  n itti  nnnsnn  in  
i   n i sana a n    snnat  nts     nat ni sat a   n   n  t isti  in     ia  nnnsnna  ana  s       ns n  innsnn  n     nni snn  nin i in       ninn  n 
 t nsan a   nnt s   t aa    aini in i tt   n   si  t  n tns s  a      nnnn   a nnni    t   naaan nnsi   tnn   nn  nnn a  n  s nis ast i nn  nsnaa i ns
aananni nn t a   n  at aa n n a     ns      a n  tstan  t atisa  t  it n  s s  nanaan t tt n  stsnn    t   nn n  na  aninnt   a n n as a   t   s na   
   ta n ta   ai tn  t  ian nnni   tt   ana  n  aa it tn     iin  nn naa sas snasna  n i    tn ann t  n n a ni n n  nn   s n  naininnaa   nanan aa   n 
nn n  a  s  i annaat t ns it   snaaiaii ns n nnia nn a  ntts ss n a si  ninsi   t  nnni t aats a   nannt  n snina i nta ats  n aia  tt n nin a t i    
 a an  iata ssaasain  a nn n sa in nnn a   nsnia snn      i n n anna   tn a a n  n nnn s   s   in  nn ti n ns i nii  n  ai n  aa a s  t  snnan s      
a  nns a aaaa i  tnt nan nnnn  aa asi ni nni   ia   n ts  i   a aniai t  tn  nannn  aaiinnsnaaanas n as  an a  attiinnn  nas s  asntas   nnn  n  a n  
ttn    n n   atnsn na   tn  ns ansn n iaa tnts t a na ns atsi  a n s   at nt aa i   a   nn an       n  n nt   naaani  i  a tai  a nst nintaa aats ts i
 in  s i nnan snt ii sian sst ann nn sisa     a n    s  iia ti  tnn    inaia  tst aa s naaai   t  s issis nsn  a  nntntiantantnns anannaaint  nn n  t 
sa nan naatn    st sa  as ns n t nnn   n  n nn tn  i     in n iii a  a asnnn  in si a annai  si i ianstitatstsn is  na nnn ss an a n s an i annann n  
  aatn iana  snninnin taan n nitasn   nnsna   in  n nnatai n   n  s nintn s   ssn nn anitsn sai nn ni a   nnta i t  n ia ttsn  nnn nii a nan  nannsann
n   a taa an  at nt nt a     a ni asatna s na n  is tn tinna  a  nsa i i  nsninann snna  na a  n iaa a as ntnn nnt i n    tit iani n tats     snaa inn
 n a   a iasi  nn    atninas n  nans aai an nini snas  n  nn a aa naaia anian a nn    i nn ins intnn  nas  n  nin saitannnnnt   t nst in as  a tian nn
ia   na nanaants nnntna  s i n nnsnaannntatn iiaiia   a i ia   nnia aaa inan nnt aanntsss   tn   is nnnan nsn asstn a  n   nnasaiana a nt  an t  t tii
an n  ti n asna  tn at t a aati naia  a a   nai tt tntt a   tsnt i n s anassn nss iaaa i st ss n  tna   nns  tansatan   naianniis  t   nnna iiaa   in 
t  ta innin   nnt  is sann a  inn iasnai ntn   tasn s n   na a nn nn n ts nt natnann s nin st n tias nnntn snasisttnin       naistttt  tasnant  nna an
nnassinatiintnts  a  nnsstnta an as  tttsaainit    t  nitn annn n natsan na n snnainna a ti t nanasan t n n     ani nin t aasi  antss   a naanstni s  
an n ntitnnisii  s asni sntnanni ntniaainait  n i   ann nis  anni t   annans  a a iatana  n nn ninnn t ii  snniiai tanni n ssaas  a aa    tnas at aaii
nnannann sn snni nna ia  nsin nnn  na naati anssnni s n  snnn nati sanits ass nn tasai annnsttntt  nast a naan  aanit   nn tanasi n nnn i in nnasts an
nn naa nss tanst aan stnnnn  n  it naasnia saast i ananssaan nsi  nitatsinain ann sannt s  ninit n si  ni  na ta asn sa i t nnns   t tin ai naantan   
 tn n a   i nna s n tna ainttn saiinia nnsnnninnta    nais t a nanat t   tnatii aiatnsi   n a i an   a  nn n i sns tn ani   a stasa na nn  nnsiaa snna
 nat i t ss i   a aa   nitnann sn a aann  nsntaiiaitt aa nasn nsna n nn atnaa nanasnn i t  nnan nantsniaaaan i inna  it insananniasns nnnan nnnna stnn
  ttasssn snaa i  a  aii ains   nt itnnints   itntt  nan tsiaia a   n    sntiaa nsstna t nn ani naa nnanais  tinta  s  aai n aaisniaansataas n ittsn t
 n n staasnaa   nas  ai i nsn tnaa nns i   n iainatnaiaanaa nnaaa nnsn  in asa   ssa inai tnaint  ain nasii saa an nsnt ntnan ta  intna   nnntanti   n
ai naaa anaann ns natn aaitatsa   s  ntttn  nsiinasa inssn   naats i n  nna  saaistnantnaianan tsaaa n ann ntnnn nanninai  naaasan asaan sna ns nta a 
i na saaastntnts an nnnnn a ainnnasii ann nn ni annn  ntts nnn tniasinnannt tannna aii atnn n nana a snntnni ntn saitai sattn nnt snnnatt anani snn a 
 nnannantnanaai  sn isannsni snn t naannn   tnn nnani tnaa n nttnnannn tant nt a tt an isatnninn nnn ntsnsatsin tinanaa aa nnn   tssn n nsnantsasnn n 
nniat  i nstiiinnatai  tin  ints a na snt  tistnnn a asnnnnaia a n nan saaannniia niin   s nnsnnanntn s t tss  naisn ann sns tttasanan  n  iisnsnnnsi 
nnnns stannsnti aatnna asnstattt  nisinnatin    inannnnaainsaiissn nasttanniitiainntntsia  tnnnnaan tnstnntnn it sn n iiani iainsnstasn a nain ntnnsna
aa nnnintn at i snnnians st tatin tntaas aa  atsanansininiia nnat nnannaanss naas  iitatsna natani n nattn sannnaatsanitn naaint aannansntniiasaaannna
nninn nsti snstn n  n an nnsi a nn aiantaaan n iaaatni tt ns n  intannnn nt nasasaa aastas iansiat ns nntnantsnat t n  in nn stn iaiit n snnaiintas na
 nitii nnaninitnnn ast intsnasat tn nstannnnssnsnnnsnsnnsinninsnsnta inntnttn  at nst an tnsassaiat st ssatna nasna nasnn nntnnasta tn ns ta t nt nn a
nnsnaa nais atainnsn nsta nsi issntannnna annai itans   annisntnaaistnsasaist  ann ns itnaanitinaniss  nn snain iniia ia ti t a innassssat ansstninntn
anis  as tai ntainannisast n at naainsaia nisisntannaatan ainsatnsantnnnattasnnns tnaaanss nsiiniintaa nsnnatn aia nainns annnannnisainna  n nssiitnsa
nansn ni satatti nsasianianains ia nininatnninsa nnnnnnaan antanasninn  anaant stni snnnnaaa nstiannannntna tssannantsssn sann niit nattasisnsaaaan tn
 nsast nnt isannnianasaasasnnt nansiaiainnstsinntiiinniana aaiananaaannaanisn aasntinnsnianitn ii nasniasinttnn nsaniia ttaaaaaan nnt nnt t aatt ann i
tn ansnna nantnsnnnnana natisnsin tntinasiiitannnsnasiitiaa nnnninssnstnnainnnntn nsn tnaan sttinn snnai nnsnnnanitisannnnntans a  aainnnn n nnniaasis
n itsnn nnaitaantinas  itaaaanntaia nat  n snsnaiiisnnnnnnsaainnsitnsainnsnantt  innna nnstnnn nisanaanatntntns aann tasantanannn anisiiinanninnana tn
 nnn tnnasis nnnnnntnnnsaatanansnaasiniaanasi iasninttinniasn  n nin inianaasnaia nia nnnnnasaaannnasnaiiiistiataniintn nnn asanaataaitnnannt annissn 
tnnaniatnnantnanaanttanaaasinntnnntiasannasnnstnssnitnnnntnn nn nainnian nnantnnaiinaittsttntanntn issanna nsniniai asninanianantnasnntiatinaaat nnsat
iantssnitaisaaitinannnttisantnst nnssa atsastnnnaiainnianasna snas nsaininn iiantnaanasnaaaannatnnattanasassiintsansssniasnninitsnnnaaisnnat nintn aas
nsanaananaisniasasa nnnntasasastnnaasnanaata intnnsi iniantn ssaaisatntininnnnntasntn nianan natnnatnnnannttatnnsn naiiannnanntnasnsnaittnsas snaiatsa
nsnatntss inaatianaissaiinasatnsiinsssaasnn annaatsanssna aaasatainannaas  nsnnaatatsiainnnntansnant inasnntntnnsianataissnaitantasiiansnaiaanantaasit
an tnnn tnaasininnnnaantnn asnnnan nnninnin nsiinnainanasiitnitnannatinnaaantnnt nnsansnninaaasnanattinnaiianattannntnnnnnsninatani nintinasnnninnatat
ttnas snaintasaaatnanaiaaanantninntntnsnnianstnnsnnstissaintan tntnaiinianntinntntiniassnnintintnssinsnnsna anntnsnnnsn ssnanatnnsnanasinanaanaatsnsnn
snsi natanannsitintnaaiaanastanintt asanaaanniiitiiatinsnitiannsinininantttanaisanssnsnnnns asitinanittninaintistntntsinnnissanstatnntiniittnnnaias an
tnananannantannnnnttnannaiinnnaantsinia naatiantaannannnsnnanstn annnasninstsnnnsntnnsttiaistntanttanatannnanntnasaiaiaainnainnnsiaiaaainasisniitnsnnt
nanntaannantaannnnnntsasttnntasaaaatanatttatittnnntnnannsiintstnnnnnaninanaanannnnnnnnnsiantnsasnsnsnanstantnsnaannttntsnnaiannnstnannaaanntnnnnnannis
nansiaannttinannnntninasnnsanainaaanansntntanstsnannansstaaaaiaantaiatniataiaiaatsnssntaitnsnaaiasaasantntisnnainanntasasntnnanatnatnitsannannaisisnns
snasnssanaisnntaasnntiassnaanannitasatnnsininannisisnttitnnaninaasissasatasnaanaannnsnisinsaasatnsatniaiannnatnnnntanntaanannanaatnsasiannniannaansaan
anannnnnaianisnisnassinaitantnntaannnntnnnnnainaannsaaantansnntiiaannnntniitannsatattnannnsasannnatsnnaatnninntsntaanntaniniannnaanaaiaainanntinsnataa
nnsannnssinntatiaaninnannitnnattnanannaistaitiianinnniassnnainsnsasttitniatnaanainsstnnnnniniannanaasinnsinnnstnsntansaatasnntatiiinanasnntttntnsainsn
nnannatntnnnnantnaaananansanaisnaainnnntnitiiatniannnnnstsnnistaitannnsaisanssinntinnnnnaaaassnittaainatnnisssnaninsatatatnaintnannaniaaitnnntntnnanan
nstnnsiannnnatiatnaaaannnnntaaaatisnastnsnianinnnnintnaaiiitsissnsnsnsnatinsanaaaaanaanaasnsannsaannsanaintnntsssnaintnnastnsaannstinaaastaannnaannann
atnsnnnnnniaiatnasnntnnniannantinanantninnitsnnnnntnsninsntninsntasntntasnnninsanssnnaasnaanannnataannsnnnnnainsninntannsaaasatsaitnnnanannnitiannstas
aannnnainnatnintatatnasnnnnansnntansnnaanntnniaassanaininnatatnnatttaaanaatatantsaaitttnnasninastsnnnisnitintanasnttninsiatinsssnnaaisannaansiaaannnis
sistsiaasnnnnnannaintnnaiaitatnnnaaannnaaniintasnanatnnnantanntnnnnisnsantntaataantnnnaaniiiaannstttnstaaintannnatsnaaiantntannnnntannssnnintannnisnnn
tnntasninatnanannnnaatinnainnnsinnnnaatinianaaisnaantttainsnitnaninnnasantsntsntasattnannananiainsanntnniasantaantanatistinnsnisannassasnntinsnninanst
anntansannttantinnaaansinnnainannnnnntiniininnntssnaaatnanasnantnttnnsasiiiannnnssntannstinsinattsnntnasnannaniannanaantannntannninnatanaisnaaansnaaaa
ssnnnninniitntsnnaaattaaananasstttnnssnstnttasasnsiaannainintannsiaanniintnntaisssntannasasaanntiastnssanntnsnnssnsnntnattnaiitnniaaisinniasnnasaaiinn
iniinanasntnnnstnnsanntnnnastsnnnaniissntainnanitnanassannnnnaatiiaiisnnnasitnnnsnnntantaaaaiiinnntatnaaaaninaniatiasannnnninnannnsatiaiianttnnnnnaasa
tnisanaitnansnntnansannannninainnntnanainnstannninattitsninsaananttaasaansnnattinnnnanisannttnnnanasnnastinninstsanattntnsnnatantssnttninintataainsnst
nanisnnnstiasnnnsnnasanaastatinsnninnsnnnnnisanisnnanintninaiiaainstntansanntnnntatntatainnntninsattnaiasinttnnainsiantnnnnninsnnninatniaiainnnsiainnn
snntnnnatnntanisintsinatintaisiiansanatnannnnannsitaaannnasannsaanaaasatiaiinatisastnitnntsstnanaanitttntaatissisnsnnsniaaaanisnanaaannnsaisnnsaannntn
ansinaaisnntiantsnnniaantnanaanaaaasatnssnaatinnnaaaittsnasnaanaannnnannnninnitniannnnnsnsnnnaininnaaannatiaaansannnnnannnaannaatsnnsnnaasnaaiaiinsani
ninannnaantnsssatananssnsnsatannninnaatsiaananntnnnnninainttiatsnnnsnsanintnniasaisnatanniatannsnnnnianannnasanannnntsansniataasannnnntannaiaanassnsnn
tatsannninannitnntnninttnnannantaasssatasnnannnnnsnisntainnanintntiainnnnnnaasnnanitannsiaaantsaiaasaniainnnnsiaainnnsnntitnatasnianiiaaatasattiinnnan
astnnntnnaiinnnannantnntsniiniantnannassnnitnansnaniaaannnntinnanasatsinanssaiiintannitnannninaitnnnnasannaaaniainanatansnstninnnsnaatsnntianniiintnan
sntsnnsiansnsiannnnisisaiasininstiiaaaannanntnisasantnaansnaaaianitnissisananitnttaantsntnniaananannaaintannniansannannaatnnistnnnanansnattannnnnnanit
ntiaasntninnsaianssnsstaisisnannaiasinnianstitatstsnnnnninnnnannansnnnnannaannanntninsaanianansnninninnnasantasntininnsnaiinaasnnataiisanisnnntntsnnnn
tnnsnnsatasaininnitttnntaantnnianttsnsnnninnsaniaannaiannisstantnaansataaintnnsnannsasatnaninasnsiatniasntannniiniaaanannnsstsnnannaitnniaanaasnsitnnn
tsanantitananinininsansnaaannsnnaaastnnanininsnainnnnsnansianaannanissnassninninaannnnaaanianiannininsainsaaiaananansananasaitannnnntinanstnnnasnaiata
anniataannanaantsantatninnininnsnaannntatnnanantnnaatiatnaiataaaatnatnntnsnnaaannntnnsiannnanitsaasstnitnninnasaianatantaanssnntiianstnntntnnsaiasatia
astansnaiaaansanainantnttnnntsntnnntaanassntsiaiaaainstnsanttnaiantsantnnanaannaianniisntntisnniiaannnntitanstanaannttistnnniasinnaaniianntnasntanstan
natinnaaantanntntiaannasitaastsatiasiannnisnasisttninntinnaaastiasasaanatannnannnassinatiintntssaannsstntassnasntttsaainittstanitnassninasatnaananasnn
ainnanttinsnanasanaanintsanisaantnitaaaiinnnaatnnsianaasnannantitnnisiiisininnsntnannistaananasntatainanaanisnanniasaannansnansiatanatntnsninnntniiisn
niiaisnnnnnnninnatinaanttnasnnsaaiinnannanntissnnitnssiaansinnntnasnnaatiinnanntsssainaannatiaiasannassttntasaisnaassnnnisnaainatiataniaatsannainssaan
ansniniannastsianatnaaiinstanstnnnnstnnnnnnaitiainsanasaastnnananssaanaannnsnisantssiaannntaannsininitnnsitnisnasnaasnisaitnnnnssnttinassnaantanantnin
aninnnannnnsnsainttntannnnnsnnsnnninntaaanaisananiatintanissntaaiatnsinnnanaannsnssiniasnsanaaninanstasainnnninnsiaanaatnnatsttnininsiaanisnanannsnnna
anntnsntaiiaittatsnasnaninannaaatnaantnianntianaanstnantsniaaaansninnaiitnatssaatniannsnnnaninisnastnnattasssnatnntitataiitnannanttaannasaaaitnttinana
atsasaaisininsnantnsstnastnnsstanaannniinsatnnnaaanstanniinannnniitniiaannnatintaanatnitantnnnasnainsnsnnaanannsaaaninsaianainantnsnnaaantanannsasaaan
tsinaisnnnnsnaattnasiiaattannntnantnanatatntasnnnnntantistsntnaaanntninansaainaaaitatsatnnannnsnsainnsasainssnnnsnnnniniisnainannnisaisaitninntsaaanna
nnanaannnanninaianaaasannansnnsnaasantasainnasaaastntntsttannnnnnnainnnasiistsanntniannntnttstnintniasinnanntntntsanaiiisasininiataaaanaatnntnnsitsits
attnnnaisnnnattnaanassnnnsaanannaninanasannnisannsnisanitiiistnantnnanntnatnaaianttnnannnnnstnntisttnnaisatnninnnnnantsnsatsinntnssannaainanttssninnsn
antsasnninnniatnitianantansasntntaainniansnsntntistnnnaaasnnnnaianananassaaannniiaanitstsnnnisniitiisaatssanaisntanasnssnnananntssantaiinstnnannnnssna
ntianniaatnnaaasnaanaiiiannataaisiniaittnnaannitananninasttanniitiainntntsiattnnnnaanaasainnannitsannttainsiainsnstasnninainaantnnnaitnnnintntnaiaanan
innnstastinatntaasisassntnansnsntannannatansatainnannaasniitatsnanannainntitniisannnaatsanitninnniinaannansntniiasaaannnanninnasnsnsnstnansnanataanant
iaiantaaannaiaaatnitninstssntianatnntiantnanaaastasnnsinnannsinantataatantinntnnntisiiaiittasnnaiintasnntnitiiiitsianansitaststtinatasttnttnnninnsitnn
isnittnnsnnnnanaaaatinntnttniattiniannnnsnnnntaistnanininnasnasaintsnntnnastannansatatnssnnsaasnntanaisinansttannstattaiissntannnnannitnnitansstnantts
aiiannttntnstnntsnansttaansnainasinsnaitsnainaatnnaiaiantisinnassssatnsnsinnasainsansinitaistttnntansntnnntaanaainsaianiianntiaanssannainsatnsantnnnat
tasnnnssaaitassnnsiiniintaataaaanaaaiaananaiaannnannnisainnaaniannntttistanannisiattniansasianianainsnnnnininatnninsantnntnnninantanasninnsanaanttsana
snnnnaaastattsnstiaannstssannantsssnnnnaaniitassnnnntanasiniatnnintttnntnstnnnsiasannannnaaanansiaiainnstsinntiiinnianastinananatitnnasanaaasntinnsnia
nitnassnasniasinttnnnsitnnsnttaaaaaannaisnntaiaatttnnaitnnataniinantnsnnnnanasnanniantatntinasiiitannnsnasiitiaaiaannaainaniaaiananssnnsninnisnsttinna
siininnsnnnanitisannnnntansiasansnsnannaasntssnnnitsnnannninsnnintinnainstanntannnatanaaiaaisnatanstannsnntniaananaisnnntttisitnannstnnninnnnanstansat
nniaannnatnsnnnaiiinanisiiinanninnanannannntnsinanannnnnntnnnsaatanansnaasiniaanasiisasnaitsnnttttaanninntitaaantninaniannnatiansanssatanninatananania
atiinnnnnaianttiaannstaaaannissnntnisaiiiaasnsnasasnsianatnninnanaananiisnntnntnatsaanaiiaanannaanaatasnnnantnnaiinaittsttntanntnanannaitnsniniaittnns
nnnnsaainsnnttsnnaittntsnnsatiantssnitaisaaitinannnttisantnstaisntnatsastnnnaiainnianasnaannaansaininnataaitsntnsssntnntnnantanainainsasnianiantsnnnna
nnnnaaaannittttannintnniisannttaniinatnnnitiannnntasasastnnaasnanaatanttsaaaniniantnatnstnnaatinntsaaaanininnnianannitaannannnsniianstiinnaiiannnanntn
asnsnaittnsastnaaaanaaansissisninaatianaissaiinasatnsiinsssaasnniassainatasiaiaaasatainannaassnsnnaatatsiainnnntansnantasisannitainnntasaainnsnssniaaa
ninnatiinaninnstaissatnnnnnntsitnnainaaitnntasnnnanintasiatsnsiinnainanasiitnitnannatinnaaantnnttaaiaatnitaannaatannnsassntnsnaaasnnaantsttntinnnatnin
tinasnnninnatatttnaststaaastnatsnnaaattainiiiannannsinnnanannnatsstnsaaassatitntnaiinianntinntntiniassnnintintnssinsnnsnasstttannnttissnanatnnsnanasin
anaanaatsnsnnsnsiantsanstnnatsataisnansaatianttnasanaaanniiitiiatinsnitiannsinininantttanaisanssnsnnnnsansstnansnnnniatsasannaiintnnitaiinnnnattastiia
nsaiatsinantnananannantannnnnttnannaiinnnaantsiniaaiansaiaaainnanniannnnaiaannnasninstsnnnsntnnsttiaistntanttanatannnanntnasaiaiaainnainnnsiaiaaainasi
sniitnsnntnanntaannantaannnnnntsasttnntasaaaatanatttatittnnntnnannsiintstnnnnnaninanaanannnnnnnnnsiantnsasnsnsnanstantnsnaannttntsnnaiannnstnannaaannt
nnnnnannisnnaanaininntinnanitnastsniaaianaaitsianannnnanntannsnsnnanaaiaaianinnnnaanatsstatisnnnainnnaanninnaaiinttnnannanininttnitnnananinnsitannnina
ntntatnaannnntanianannniistntatsnannsanninnssasainisniatnnainanntnnnaannnatitaiitaisnnnaannsntanstnaaaaninaittnatntinnnnaatnannaaannnasaantnataiiiitat
niaatnnsaatiatannnnaasnnnnnnattnaaannnnannaninntnasnannntantttainnaisninstaiannnitiaasaaatiiatasisaasanatntasnaannnnianinitsinitianatsnnannniaiiitiaai
naaannnattnnantnannsntsstnsanasntisataananasatntnnnansiannastininaansaaannannntnantsinaatannsnannaaanntaisttiasaaaisisnnnnnsnnnnsasiannittanasntnanntt
iaasanniistiatannnnstasnittnnttntnnisttnanttnnnaaiaiainaninsinaannatiaiitatnaassinnnannnnnisitnaannsanntasnnnnannnisnnnsinatnnititaantttnnantiitisnnna
tiniasantntnsaaanasnantnsnnnsniantsstntaiaannttntatstnnnananisnaantaiatnnnitnanasaiiannnanassansntinasnnsnintisnaannnsnna"


def main
  s = $String
  print "[tanasin] : ", (/tanasin/ =~ s), "\n"
  print "[tanasinn] : ", (/tanasinn/ =~ s), "\n"
  print "[TANASIN] : ", (/TANASIN/ =~ s), "\n"
  print "[TANASIN](i) : ", (/TANASIN/i =~ s), "\n"
  print "[ttnt] : ", (/ttnt/ =~ s), "\n"
  print "[ttnt] : ", (/ttnt/i =~ $String), "\n"
end


main
