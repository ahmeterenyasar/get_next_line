*This project has been created as part of the 42 curriculum by ayasar.*

# get_next_line

strjoin yerine linked list kullanılacak
3 yapılı bir mantık haricinde bir şey mümkün değil ama ekip umarım bunuda intihal olarak anlamaz: get_next_line toplar çıkarır ve temizler buff kadar okicaz new linea kadar çıkarıcaz temizlenmiş halini statiğe yazacaz.
aşama aşama leak bakarız ya da en son leak bakarız idk

burkay ve berkay ve rüya hanım ve disiplin için anlamasalarda biraz daha teknikal bir açıklama şöyle olabilir

her read() çağrısı bir "parça" getiriyor bakınız "parça". Genelde parçaları birleştirip tek bir uzun string tutuluyor ordan parse ediliyor diyelim ayrıştırma falan temizleme türkçe söylemek gerekirse. Ben bunun yerine, parçaları olduğu gibi bir listede tutacağım, bu fikri bana veren aakyuz ve diğerlerine teşekkür ederim akran öğrenmesi olduğuna dikkat çekerim onlar öyle mi yaptı bilmiyorum ama linked list ile yapıldığını duymuşlar ben de kendi mantığım "KENDİ" mantığım bana ait -bakın klavyeye basıyorum şuan- kodlarla yazacağım. Listeye baktığımızda şuna benzer bir görüntüyü görececeğiz:
head -> [BUFFER_SIZE byte] -> [BUFFER_SIZE byte] -> [BUFFER_SIZE byte, '\n' var] -> NULL
gibi gibi
anlamadınız ama olsun anlarsınız