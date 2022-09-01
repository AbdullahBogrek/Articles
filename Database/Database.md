# Veri Tabanı

- İçerisinde verilerin belirli kurallara(veri tipi, uzunluk) göre saklandığı yazılımdır.
- Veri tabanı içerisindeki verilere **Veri tabanı Yönetim Sistemleri (Database Management Systems)** kullanılarak, veri manipülasyonu gibi çeşitli işlemler yapılabilmektedir. 

## DBMS (Database Management Systems - Veri Tabanı Yönetim Sistemleri)

- Bir veya daha fazla veri tabanını yönetmek, analiz etmek için kullanılır. Veri tabanında tablolar oluşturabilmek, silmek, güncellemek ve sorgular yapmak gibi yöntemleri gerçekleştirmeye olanak sağlar.

- Veri tabanı yönetim sistemlerinin sektördeki gerekli ihtiyaçları karşılamk için geliştirilmiş çeşitleri vadır. Bunlar:
    
    - Relational DBMS
    - Hierarchical DBMS
    - Document DBMS
    - Network DBMS
    - Object-Oriented DBMS
    - NoSQL DBMS
 
-  En çok kullanılanı İlişkisel Veri Tabanı Yönetim Sistemleridir (RDBMS). Fakat NoSQL veri tabanları da son dönemde oldukça falza kullanılmaya başlandı.

### RDBMS (Relational Database Management Systems)

- Verilerin, birbiriyle ilişki içerisinde olan tablolarda saklandığı yapıdır.
- Tablolar, veri tabanını oluşturan en basit yapılardır. Her tablo, satır ve sütunlardan oluşmaktadır.
- İmplementasyonu kolay ve güçlü bir yapıya sahiptir.
- Farklı büyüklüklerdeki kurumlar tarafından kullanılabilir.
- Her bir sütunda yapılan kayda ait özelliğin verisi bulunur. 3 farklı sütun tipi vardır. Bunlar sütuna girilen değere göre değişmektedir.
    
    - **Single**: İçerisinde tek bir değer bulunduran sütunladır. 
    - **Composite**: İçerisinde ayrı ayrı tutulabilecek halde bir arada tutulan verilerin bulunduğu sütundur. İsim-soyisim buna örnektir.
    - **Multi-valued**: İçerisine girilen değerin çeşitlerinin olduğu sütunlardır. Örneğin renk olarak "sarı, kırmız" girilmesidi.

- İlişkisel veri tabanlarına "ilişkisel" ön ekini almasına sebep olan ilişkiler 3 tanedir. Bunlar:

    - **One-to-One (1:1)**: Bir tablodaki bir kayıt, başka bir tablodaki yanlızca bir kayıtla ilişkilendirilebilir.

    - **One-to-Many (1:M)**: Bir tablodaki farklı kayıtlar, başka bir tablodaki farklı kayıtla ilişkilendirilebilir.

    - **Many-to-Many (M:N)**

- İlişkisel veritabanında farklı tablolar arasındaki veriler, çeşitli anahtarlar vasıtası ile birbirlerine bağlanırlar. Bunlar:

    - **Primary Key**: Sütundaki her bir değeri eşsiz olan ve tablodaki her bir satırı tanımya olanak sağlayan sütundur. Bir tabloda önceden mevcut olabilir ya da DBMS tarafında "auto-increment" edecek şeklinde oluşturulabilir. Her bir tablonun tek bir **primary key**'i olabilir. Bu arada her ne kadar tabloda bulunan sütunlardan biri **primary key** olarak seçilebiliyor olsa da hassas verilerin(kimlik no, kart numarası) **primary key** olarak seçilmemsi gerekmektedir.

    - **Unique Key**: Tablo içerisindeki her bir değeri birbirinden farklı olan sütundur. Bir tabloda birden fazla bulunabilir.

    - **Foreign Key**: İki tablo arasında ilişki kurmak için kullanılan sütunlardır. **Foreign key** değerleri, ilişki kurulacak olan tablonun **primary key** değerleri ile aynıdır. İlişki kurulacak tablolardan birinin **Primary key**'i diğerinde **foreign key** sütunu olarak bulunur.   

- Veri tabanlarındaki hataları minimum'a indirmeye ve gereksiz veri tekrarının önüne geçmeye çalışmaya **normalizasyon** denir.
 
    - Normalizasyon uygulanmış veri tabanlarında arama algoritmaları daha hızlı çalışır. Veri tabanının daha az yer kaplamasını sağlar.

    - Veri tabanlarında normalizasyon olmazsa bazı anomaliler ortaya çıkmaktadır. Bu nedenle veri tabanı normalizasyonları yapılmaktadır. Bu süreç adım adım ilerlemektedir ve bir adım tamamlanmadan diğerine geçilememektedir. Bunlara **Normalizasyon Formları** denir. Bazı anomalilier şunladır:

        - Insertion Anomaly: Veri tabanına yeni bir kayıt eklerken görülen hatalardır.

        - Modification Anomaly: Veri tabanındaki bir verinin güncellenmesi sırasında görülen hatalardır.

        - Deletion Anomaly: Bir verini silinmesi sırasında ortaya çıkan hatalardır.

- Gerçekleştirilecek olan her bir “transaction”un ACID (Atomic, Consistent, Isolated, Durable) olarak da bilinen 4 niteliği sağlaması gerekmektedir.

    - Uygulamalarda başarı veya hatayı garanti eden operasyonlar listesi olarak tanımlayabiliriz. SQL kodumuzda herhangi bir hata meydana geldiğinde işlemleri geriye alarak güvenli bir duruma getirmeyi sağlar. Günlük olarak kullandığımız ATM’de para çekme esnasında ister yazılımsal isterse donanımsal bir hata oluştuğunda paramızın hesabımızdan çekilmediğini görürüz. İşte bu gibi durumlarda Transaction yapısı devreye girerek paramızın hesabımıza geri dönmesini sağlar. Veritabanında gerçekleşecek olan işlemleri toplu olarak değerlendirip, herhangi bir işlemde hata olması durumunda, tüm süreci geri alıp başlangıç durumuna getirir. Böylece kritik işlemlerde veri bütünlüğünü garanti altına almış oluruz.

    -  ACID kavramı, elektrik kesintisi, sistem çökmesi gibi durumlarda geçerliliği garanti etmeye yarayan veritabanı özelliklerinin bir dizi özelliğidir. ACID özelliklerini karşılayan veritabanı işlemler dizisi, transaction olarak adlandırılır. Bir transaction özellikleri aşağıdaki gibidir;

        - **Atomicity**: Bir transaction başarılı bir şekilde tamamlanabiliyorsa gerçekleştirilir, eğer herhangi bir noktada hata çıkıyorsa hiç gerçekleştirilmez ve veri tabanı transaction’dan önceki haline geri döner.

        - **Consistency**: Veri üzerinde yapılacak bir işlemin veri tabanındaki herhangi bir kuralı ihlal etmemesi gerektiğini ifade eder. Örneğin, bir sütuna belirtilen veri tipi dışında veri girmemesi. Bir transaction’da commit veya roll back işlemi gerçekleştiğinde veritabanı tutarlığını korumak önemlidir. 

        - **Isolation**:  Transaction tamamlanıncaya kadar, bir transaction diğer transaction’ların sonucuna erişemez. Bir transaction oturumu başladığında veriyi değiştirecek Insert, Update gibi ifadeler, sadece geçerli oturumda görünür. Örneğin, stoktaki bir ürünün aynı anda iki farklı kişi tarafından sepete atılamaması.

        - **Durability**: : Elektrik kesilmesi veya diskte çıkan herhangi bir sorun çıksa dahi tamamlanmış bir transaction’un sonradan kaybolmayacağını ifade eder. Çoğu veri tabanı yönetim sistemleri, gerçekleştirilen transaction’ları “**transaction log**” denilen işlemler geçmişine not eder. Bu sayede sistem güncel durumunu korur.
    
    - Bir transaction ilk olarak çalıştırılabilir bir SQL ifadesiyle başlar, COMMIT veya ROLLBACK işlemlerinden biri gerçekleşince tamamlanır.

        - **COMMIT**: Veritabanında Insert, Update, Delete gibi işlemler başarılı bir şekilde gerçekleştiğinde COMMIT komutu ile değişiklikler kaydedilir. Böylece Durable kavramına göre veritabanına kalıcı olarak kaydedilir.

        - **ROLLBACK**: Veritabanında Insert, Update, Delete gibi işlemlerden birinin başarısız olması durumunda ROLLBACK komutu ile tüm sürecin geri alınması sağlanır.

    - Transaction süresince işlem başarılı bir şekilde gerçekleşirse COMMIT ile veritabanında kalıcı bir şekilde kaydedilir. Transaction süresince herhangi bir nedenden dolayı işlem başarısız olursa ROLLBACK ile tüm süreç geri alınır.

    - Tüm bu transaction yapısı, kritik işlelerde verinin güvenli bir şekilde veritabanına kaydedilmesi veya hata ile karşılaşıldığında sürecin geriye dönmesini istediğimiz durumlarda, bir tablo üzerinde değişiklik yapmak istediğimizde ve diğer tablolarda da tutarlılığı olmasını istediğimizde kullanılır. Buna bankaları ya ad e-ticaret sitelerini örnek olarak verebiliriz.

-  SQL tabloları üzerinde bir veri araması yapıldığında, veritabanında saklanan verilerin sayısı arttıkça performansta düşüş yaşanır. Dağınık yapıda olan verilerde istenilen veriyi aramak için tablo taraması işlemi yapılır. Sorgu işlemlerimi yaparken **clustered** index ve **non-clustered** index kavramlarını bilmemiz SQL performansı açısından işimize yarayacaktır.

    - Sql’de indexe sahip olmayan tablolara **heap** adı verilir. **Heap** bir tabloda bir select işlemi yapıldığında, SQL tablodaki kaydı bulabilmek için bütün kayıtları teker teker dolaşır. Kaydı bulunsa da, birden fazla kayıt olma ihtimaline karşı tabloyu dolaşmaya devam eder. Bu da SQL için ciddi bir performans kaybına yol açar. Bu işlemi küçük boyutlu bir tabloda yapmak kolaydır. Ancak artan veri miktarına göre bu işlem vakit kaybettirir. Indexler ise tablolardan veri çekmek için gerekli sorgular çalıştırılırken gereken süreyi azaltmak için kullanılırlar.

        - **Clustered Index**: Veriyi SQL'de fiziksel olarak sıraya sokan yapıdır. Aslında hepimiz **clustred index**’i tablolarımızda kullanıyoruz. Tablolarımıza tanımladığımız her bir **Primary key** aslında otomatik olarak bir **clustred index** yapısıdır. Her tabloda yalnızca 1 adet clustered index olabilir. 

        - **Non-clustered Index**: Bir kolonu **Non-clustered** index olarak indexlendiğinde, arka tarafta yeni bir tablo oluşur ve bu tablo sizin indexlediğiniz kolona karşılık kolon adresi tutmaktadır. Bir nevi pointer yapısı gibi düşünülebilir. **Non-clustered** indekste verilere direkt erişilemez. Elde edilen indeksleme yapısına erişmek için kümelenmiş indeks yapısı kullanılmış olur. Bu duruma bir kitabın ilk sayfalarında bulunan içindekiler bölümü örnek olarak verilebilir. İçindekilerden bakılarak istenilen sayfaya gidilir. Non-cluster index de tam olarak bunu yapmakta.

- Devam edecek...

## Alıştırmalar

### **Alıştırma 1** -----------------------------------

- film tablosunda bulunan title ve description sütunlarındaki verileri sıralayınız.
- film tablosunda bulunan tüm sütunlardaki verileri film uzunluğu (length) 60 dan büyük VE 75 ten küçük olma koşullarıyla sıralayınız.
- film tablosunda bulunan tüm sütunlardaki verileri rental_rate 0.99 VE replacement_cost 12.99 VEYA 28.99 olma koşullarıyla sıralayınız.
- customer tablosunda bulunan first_name sütunundaki değeri 'Mary' olan müşterinin last_name sütunundaki değeri nedir?
- film tablosundaki uzunluğu(length) 50 ten büyük OLMAYIP aynı zamanda rental_rate değeri 2.99 veya 4.99 OLMAYAN verileri sıralayınız.

    ```sql
    SELECT title, description FROM film;

    SELECT * FROM film WHERE length > 60 AND length < 75;

    SELECT * FROM film WHERE rental_rate = 0.99 AND replacement_cost = 12.99 OR replacement_cost = 28.99;

    SELECT * last_name FROM customer WHERE first_name = 'Mary';

    SELECT * FROM film WHERE NOT (length > 50 AND rental_rate = 2.99 OR rental_rate = 4.99)
    ```

### **Alıştırma 2** -----------------------------------

- film tablosunda bulunan tüm sütunlardaki verileri replacement cost değeri 12.99 dan büyük eşit ve 16.99 küçük olma koşuluyla sıralayınız ( BETWEEN - AND yapısını kullanınız.).
- actor tablosunda bulunan first_name ve last_name sütunlardaki verileri first_name 'Penelope' veya 'Nick' veya 'Ed' değerleri olması koşuluyla sıralayınız. ( IN operatörünü kullanınız.)
- film tablosunda bulunan tüm sütunlardaki verileri rental_rate 0.99, 2.99, 4.99 VE replacement_cost 12.99, 15.99, 28.99 olma koşullarıyla sıralayınız. ( IN operatörünü kullanınız.)

    ```sql
    SELECT * FROM film WHERE replecement_cost BETWEEN 12.99 AND 16.99

    SELECT first_name, last_name FROM actor WHERE first_name IN ('Penelope', 'Nick', 'Ed')

    SELECT * FROM film WHERE (rental_rate IN (0.99, 2.99, 4.99)) AND (replacement_cost IN (12.99, 15.99, 28.99))
    ```

### **Alıştırma 3** ----------------------------------

- country tablosunda bulunan country sütunundaki ülke isimlerinden 'A' karakteri ile başlayıp 'a' karakteri ile sonlananları sıralayınız.
- country tablosunda bulunan country sütunundaki ülke isimlerinden en az 6 karakterden oluşan ve sonu 'n' karakteri ile sonlananları sıralayınız.
- film tablosunda bulunan title sütunundaki film isimlerinden en az 4 adet büyük ya da küçük harf farketmesizin 'T' karakteri içeren film isimlerini sıralayınız.
- film tablosunda bulunan tüm sütunlardaki verilerden title 'C' karakteri ile başlayan ve uzunluğu (length) 90 dan büyük olan ve rental_rate 2.99 olan verileri sıralayınız.

    ```sql
    SELECT * FROM country WHERE country LIKE 'A%a';

    SELECT * FROM country WHERE country LIKE '_____%n';

    SELECT * FROM film WHERE title ILIKE '%T%T%T%T%';

    SELECT * FROM film WHERE title LIKE 'C%' AND length > 90 AND rental_rate = 2.99
    ```

### **Alıştırma 4** ---------------------------------

- film tablosunda bulunan replacement_cost sütununda bulunan birbirinden farklı değerleri sıralayınız.
- film tablosunda bulunan replacement_cost sütununda birbirinden farklı kaç tane veri vardır?
- film tablosunda bulunan film isimlerinde (title) kaç tanesini T karakteri ile başlar ve aynı zamanda rating 'G' ye eşittir?
- country tablosunda bulunan ülke isimlerinden (country) kaç tanesi 5 karakterden oluşmaktadır?
- city tablosundaki şehir isimlerinin kaç tanesi 'R' veya r karakteri ile biter?

    ```sql
    SELECT DISTINCT replecement_cost FROM film;

    SELECT COUNT(DISTINCT replecement_cost) FROM film;

    SELECT COUNT(title) FROM film WHERE LIKE 'T%' AND rating = 'G';

    SELECT COUNT(country) FROM country WHERE LIKE '_____';

    SELECT COUNT(city) FROM city WHERE ILIKE '%R';
    ```

### **Alıştırma 5** ---------------------------------

- film tablosunda bulunan ve film ismi (title) 'n' karakteri ile biten en uzun (length) 5 filmi sıralayınız.
- film tablosunda bulunan ve film ismi (title) 'n' karakteri ile biten en kısa (length) ikinci(6,7,8,9,10) 5 filmi(6,7,8,9,10) sıralayınız.
- customer tablosunda bulunan last_name sütununa göre azalan yapılan sıralamada store_id 1 olmak koşuluyla ilk 4 veriyi sıralayınız.

    ```sql
    SELECT * FROM film WHERE title LIKE '%n' ORDER BY length DESC LIMIT 5

    SELECT * FROM film WHERE title LIKE '%n' ORDER BY length ASC OFFSET 5 LIMIT 5

    SELECT * FROM customer WHERE store_id = 1 ORDER BY last_name DESC LIMIT 4
    ```

### **Alıştırma 6** ----------------------------------

- film tablosunda bulunan rental_rate sütunundaki değerlerin ortalaması nedir?
- film tablosunda bulunan filmlerden kaç tanesi 'C' karakteri ile başlar?
- film tablosunda bulunan filmlerden rental_rate değeri 0.99 a eşit olan en uzun (length) film kaç dakikadır?
- film tablosunda bulunan filmlerin uzunluğu 150 dakikadan büyük olanlarına ait kaç farklı replacement_cost değeri vardır?


    ```sql
    SELECT AVG(rental_rate) FROM film;

    SELECT COUNT(*) FROM film WHERE film LIKE 'C%'

    SELECT MAX(length) FROM film WHERE rental_rate = 0.99;

    SELECT COUNT(DISTINCT replacement_cost) FROM film WHERE length > 150
    ```
