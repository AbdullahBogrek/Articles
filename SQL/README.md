
# _SQL_
- Yapısal Sorgu Dilidir (STRUCTURED QUERY LANGUAGE) .
- Temel kullanım alanları veritabanlarıdır. 
- Verileri yönetmek için kullanılan bir dildir.
- Verilerle işlemler yapmak kolaydır.
- Dağınık olarak yer alan verilerin düzenlenerek depolanması için SQL veri tabanı sistemi geliştirilmiştir.
- Verilerin ve veri kümelerinin modellenmesini sağlamaktır. Verileri tablolarla temsil etmenin sezgisel, kolay anlaşılır bir yolu olan ilişkisel modeli temel alır.
- İlişkisel Veri Tabanı Yönetim Sistemlerini (RDBMS) kullanan 4 tane popüler sistem vardır. Bunlar:
    - [MSSQL] :  Sunucu tabanlıdır ve Microsoft tarafından geliştirilmiştir.
    - [MYSQL] : Hem ücretsiz hem de açık kaynaklıdır. Oracle tarafından geliştirilmektedir.
    - [Oracle SQL] : Veritabanı yazılım sistemleri arasında en güçlü olan yazılımdır. Bütün büyük firma ve uygulamalarda kullanılabilmektedir. Ücretlidir.
    - [PostgreSQL] : Özgür ve açık kaynak kodlu, SQL destekli bir ilişkisel veritabanı yönetim sistemidir.
- İlişkisel veri tiplerinin ortak dili T-SQL'dir.

Bu yazıda Microsoft'un geliştirdiği SQL Server kullanılacaktır. Kurulumu [buradan](https://www.microsoft.com/tr-tr/sql-server/sql-server-downloads) yapabilirsiniz.

# _SQL Server_ 
 Microsoft tarafından geliştirilmiş ilişkisel veri tabanı yönetim sistemidir (RDBMS) . Microsoft çeşitli sürümlerele kullanıma sunmuştur. Express versiyonu ücretsizdir. Fakat veri tabanın boyutu 10GB'ı geçemez ya da veri tabanı sunucusu 1GB'dan fazla RAM kullanamaz gibi belli kullanım limitleri vardır. Ayrıca Microsoft'un developerlar için yayınladığı "developer" sürümünü ile tüm özelliklerini kullanabiliriz. Bu sürümü product ortamlarda kullanamayız.
 
  Hızlı ve kararlı bir veritabanı yönetim sistemidir, SQL desteklediği gibi NoSQL de desteklemektedir. SQL Server ile veri işleme ve depolama, veri indeksleme ve sorgulama, veri tabanı yönetimi, veri akışı optimizasyonu, veri raporlama gibi işlemleri yapmamıza olanak sağlar. 
  
  ## _SQL Server Management Studio_
  Microsoft'un geliştirdiği bir veri tabanı editördür. Sunucuları genelde "SQL Server Management Studio" ile kullanılır. Yukarıda da bahsedildiği gibi veri tabanı oluşturma, tasarlama, veri sorgulama, veri ekleme ya da çıkarma, rapolarma gibi işlemleri T-SQL sorgu dili kullanarak yapabiliriz.
 > T-SQL : Transact-SQL yani T-SQL, Microsoft SQL Server veri tabanı için kullanılan sorgulama diline verilen isimdir. Fakat MYSQL, Oracle SQL gibi veri tabanlarında da aynı dil yapısı ufak farklılıklarla kullanılır. SQL komutları "Data Manipulation Language-DML", "Data Definition Language-DDL" ve "Data Control Language-DCL" olarak üçe ayrılır. Aşağıda daha ayrıntılı bir şekilde açıklanacaktır.
 
 ## _Server Bağlantısı_

 - Server Type : Kullanılan server'ın tipini belirtir.
 - Server Name : Management Studio ile bağlanılacak olan server'ın adını belirtir. SQL Server ile Management Studio aynı bilgisayarda kurulu ise '.', 'bilgisayarın adı', 'localhost' veya '(LOCAL)' yazarak server'a bağlanılabilir. Sunucunun oluşturulduğu bilgisayar ile Management Studio'nun kurulu olduğu bilgisayar farklı ise IP adresi kullanarak server'a bağlanılabilir. Fakat ağda IP'si bilinn bir makina ile bağlatının gerçekleştirilmesi güvenlik açığı oluşturabilir. Bundan dolayı SQL Server varsayılan olarak IP ile bağlanmayı kapalı olarak sunuyor. Lakin istenirse konfigrasyon ayarlarından açılabilir.
 - Authentication : Windows Authentication, SQL Server Authentication gibi doğrulama yöntemleri ile server'a bağlanılabilir. Windows Authentication sadece 'server name' ile yapılan bağlantıyı temsil ederken, SQL Server Authentication ile login ve password ile yapılan bağlantıyı temsil eder.
 

## _Database_
SQL Server Management Studio ile oluşturulan veri tabanları "database" sekmesinin altında yer alır. Veri tabanları, tablolar veya sorgular arayüz üzerinden oluşturulabileceği gibi komutlarla da oluşturulablilir. Oluşturulan veri tabanlarında iki tür veri vardır. Birincisi satırlardan oluşan veriler, ikincisi ise log'lardır. 
 
 ## _Veri Tipleri_
Veri tabanlarında oluşturulan verilerin tipleri çok iyi seçilmelidir. Performans için oldukça önemli bir konudur. Bundan dolayı bütün veri tiplerine, boyutlarına hakim olmalıyız.

| Int Veri Tipleri | Özellikleri |
| ------ | ------ |
| bigint |  Hafızada 8 byte yer kaplar. Çok büyük tam sayı değerleri için kullanılmalıdır. |
| int | Hafızada 4 byte yer kaplar. +- 2,1 milyar aralığındaki tam sayılar içi kullanılır |
| smallint | Hafızada 2 byte yer kaplar. +- 32768 aralığındaki tam sayılar için kullanılır.|
| tinyint | Hafızada 1 byte yer kaplar. 0 ile 255 arasındaki tam sayılar için kullanılır. |
| bit |  1, 0 veya NULL değerlerini alabilen veriler için kullanılan bir tam sayı veri türüdür. Ayrıca True ve False string değerleri bit değerlerine dönüştürülebilir. |
| decimal | Hem tam sayı hem de ondalıklı sayı değerler için kullanılan bir veri tipidir. Numeric ile aynıdır.|
| float | Boyutu ve doğruluğu (ondalık kısım duyarlılığı) aldığı parametreye göre değişen kayan noktalı sayılar için kullanılır. |
| money | Virgülden sonra 4 basamağa kadar duyarlı, çok büyük ondalıklı sayılar için kullanılır. |
| smallmoney | Money veri tipi ile aynı fakat +- 214 bin aralığındaki veriler için kullanılır. |
| time |  Saat verilerini hh:mm:ss:nnnnnnn şeklinde saklayan , boyutu kullanıcı tarafından değiştirilebilen veri tipidir. |
| date | Tarihleri yyyy-mm-dd şeklinde saklayan 3 byte uzunluğunda veri tipidir. |
| datetime | Tarih ve saat tipinde veri saklamaya yarar. “01-01-1753” ile “31-12-9999” tarihleri arasında bir değerlri yyyy-mm-dd hh:mm:ss[.nnn] şeklinde saklar. |
| datetime2 | Datetime ile tek farkı 7 byte'lık depolama alanı kullanır. YYYY-MM-DD hh:mm:ss[.nnnnnnn] şeklinde saklar.  |
| smalldatetime |  DateTime veri tipinin daha az kapsamlı halidir. “01-01-1900” ile “06-06-2079” tarih aralığını destekler ve nano saniye bilgisi içermez. |
| char | Sabit uzunlukta karakter dizilerini tutar. Char(n) şeklinde kullanılır ve 1 ile 8000 arasında değer alır. |
| varchar | Char veri tipi ile tek farkı karakter sayısı daha kısa girilirse boş alanları hafızadan atar. Böylece hafızadan tasarruf edilmiş olur. Bu da 1 – 8000 karakter arasında karakter tutabilir. |
| nchar | Char ile aynı yapıdadır. Tek farkı char’ın aksine Unicode desteği sağlamasıdır. 1 ile 4000 karakter arasında veri tutar. |
| nvarchar | Varchar’ın Unicode karakter destekleyen halidir. 1 ile 4000 karakter arasında veri tutar. |
| varbinary | Değişken uzunluktaki binary verileri tutar. 1 ile 8000 arasında değer alabilir. |
| smallmoney | Money veri tipi ile aynı fakat +- 214 bin aralığındaki veriler için kullanılır. |

> ÖNEMLİ : Microsoft, ntext, text ve image veri türleri, SQL Server'ın gelecekteki bir sürümünde kaldırılacağını belirtti. Bu veri türlerinin kullanımından kaçınmamız gerektiğini ve şu anda bunları kullanan uygulamaların değiştirilmesi ve bunun yerine nvarchar (max), varchar (max) ve varbinary (max) kullanılması tavsiye ediliyor. Bundan dolayı bu tabloda bu veri tiplerine yer verilmemiştir.

# _T-SQL_

Transact-SQL yani T-SQL, Microsoft SQL Server veri tabanı için kullanılan sorgulama diline verilen isimdir. Microsoft kendi platformu için SQL üzerine yaptığı iyileştirmeleri standart haline getirmiş ve T-SQL ismini vermiştir. Transact-SQL‘in kısaltması olan T-SQL günümüz veritabanı yönetim ihtiyaçlarının tamamını karşılayabilecek yeterliliğe sahiptir. Fakat MYSQL, Oracle SQL gibi veri tabanlarında da aynı dil yapısı çeşitli farklılıklarla kullanılır. T-SQL ile veritabanı üzerinde işlem yapabilmek için SQL komutları "Data Manipulation Language-DML", "Data Definition Language-DDL" ve "Data Control Language-DCL" olarak üçe ayrılır.
#### Data Manipulation Language-DML : 
 Veri işleme dili anlamına gelir. Veri tabanına yeni veri eklenmesi, silinmesi, güncellenmesi DML kullanılarak yapılır. Bunlar için **INSERT**, **DELETE**, **UPDATE** ve **SELECT** komutları kullanılır.  
 - **INSERT** komutu ile veri tabanı tablosundan veri ekleme işlemi yapılır. Kullanımı 
	 > 	``` sql	
	 >INSERT INTO tablo_adi(sutunların_adi...) VALUES(sutunların_degerleri...) 
	 > ```
	 
 - **DELETE** komutlu ile veri tabanı tablosundan veri silme işlemi yapılır.
	> 	``` sql	
	>DELETE  FROM  tablo_adi
	 >WHERE  kosul_adi
	 > ```
	 
 - **UPDATE** komutu ile veri tabanındaki bir veriyi/verileri güncelleme işlemi yapılır.
	 > 	``` sql
	 >UPDATE  tablo_adi
	 >SET sutun1 = deger1, sutun2 = deger1, ...  
	 >WHERE  kosul_adi 
	 > ```
	  
 - **SELECT** komutu ile veri tabanındaki verileri listeleme işlemi yapılabilir.
	> 	``` sql	 
	 >SELECT  sutun1, sutun2, ... FROM  tablo_adi
	 >SELECT * FROM  tablo_adi
	 > ```

#### Data Definition Language-DDL : 
Veri tanımlama dili anlamına gelir. Veri tabanındaki veri tabanı nesnelerinin yapısını oluşturmak ve değiştirmek için kullanılır. Veri tabanı veya tablo oluşturmayı, silmeyi ve üzerinde değişiklik yapmaya sağlayan komutlardır.  Bunlar için **CREATE**, **DROP**, **ALTER**, **RENAME**, **TRUNCATE**, **COMMENT**  komutları kullanılır.

- **CREATE** komutu veri tabanı ya da tablolar gibi veri tabanı nesnelerini oluşturmak için kullanılır.
	> 	``` sql
	>CREATE DATABASE veri_tabani_adi 
	> ```
	
- **DROP** komutu nesneleri veri tabanından silmek için kullanılır. **DELETE** komutu ile farkı da budur. **DELETE** ile verileri sileriz.
	> 	``` sql
	> DROP nesne_turu nesne_adi  
	> ```
	
	> 	``` sql	
	> DROP TABLE tablo_adi    -- Tablo adına sahip tabloyu siler
	> ```
	
	> 	``` sql
	> DROP DATABASE veri_tabani_adi    -- Veri tabanını adına sahip veri tabanını siler
	> ```
	
- **ALTER** komutu veri tabanının yapısını değiştirmek, mevcut tablodaki sütunlara ekleme, çıkarma veya değiştirme işlemleri yapmak için kullanılır. Kısacası **UPDATE** veriyi güncellerken, **ALTER** nesneyi günceller. Bu nesneye örnek olarak tablonun yapısı gösterilebilir.
	> 	``` sql
	> ALTER TABLE tablo_adi
	> ADD Alan_adi Alan_türü 
	> ```
		
	> 	``` sql
	> ALTER TABLE Tablo_adi 
	> ADD (Alan_adi1 Alan_türü1, Alan_adi2 Alan_türü2, ...)
	> ```
	
- **TRUNCATE** komutu tablo yapısını değiştirmeden, tablo içinde yer alan tüm verileri tek komutla silmek için kullanılır. **DELETE** komutu ile de silme işlemi yapılır. Fakat index değerleri kaldığı yerden devam eder. 	
	> 	``` sql
	> TRUNCATE TABLE  tablo_adi 
	> ```

#### Data Control Language-DCL :

Veri kontrol dili anlamına gelir. Veri tabanı ile ilişkili kullanıcıların ve rollerin verilere erişim yetkilerini düzenlemek amacıyla kullanılır. SQL Server’da default olarak yetki sahibi olan gruplar:  _sysadmin , dbcreator , db_owner , db_securityadmin_  ‘dir. Komutlar ise **GRANT**, **DENY** ve **REVOKE** 'dur.
- **GRANT** komutu, kullanıcının veri tabanı ayrıcalıklarını tanımlar. Belirtilen kişiye/kişilere verileri kullanma, komut çalıştırma izni verilir.
	> 	``` sql
	> USE veritabani   
    > GRANT SELECT ON table_adi TO kullanici_adi
    > --- Bu komut ile  kullanıcıya table_adina sahip tabloda SELECT işlemi yapma yetkisi verdik.
	> ```

- **DENY** komutu kullanılarak, kullanıcının verilere olan erişim ayrıcalıklarını geri alınabilir ya da kısıtlanabilir..
	> 	``` sql
	> USE veritabani   
	> DENY SELECT ON tablo_adi TO kullanici_adi
    > --- Bu komut ile yukarıda GRANT komutu ile kullanıcıya verdiğimiz yetkiyi geri alınabilir.
	> ```

- **REVOKE** komutu kullanılarak, verilen tüm izinler kaldırılabilir.
	> 	``` sql
	> USE veritabani   
	> REVOKE SELECT ON tablo_adi FROM kullanici_adi
    > --- Bu komut ile kullanıcının SELECT hakkını tamamen kaldırılabilir.
	> ```

## RDBM (Relational Database Management System) 
Günümüzde verilerin her geçen gün katlanarak büyümesi sebebiyle, verilerin depolanması zorluklar oluşturmaktadır. Bu depolama ve analiz işlemlerini kolaylaştırmak amacıyla ortaya çıkan veri tabanı çeşitlerinden en yaygın olanı  ilişkisel veri tabanı türüdür.

Veri tabanları genellikle bir veri tabanı yönetim sistemi ile çalıştırılır. Veri tabanı yönetim sistemi kullanıcılara ve programcılara veri oluşturmayı, veri silmeyi, güncellemeyi ve yönetmeyi sağlar. Bu sistemler çoğunlukla bir arayüze sahiptir ve bu arayüz ile istenilen işlemler kolayca yapılabilir. **MYSQL**, **Oracle SQL**, **MSSQL** gibi veri tabanları ilişkisel veri tabanını kullanır. 

Doğru yönetilen, doğru indexlenmiş bir veri tabanı ile istenen veriye hızlı bir şekilde erişebilmenin yanında hafızayı da verimli bir şeklide kullanılmış olur. Büyük veriler ile uğraşan şirketler için bunlar çok önemli konulardır. Bunun için **normalizasyon** uygulanmalıdır.

>**Normalizasyon :** 
	Güçlü ve hızlı bir veri tabanı oluşturmanın en önemli adımlarından biri normalizasyon yapmaktır. Bunun sebebi veri tabanındaki veri tekrarlarını ortadan kaldırılarak ve veri tutarlılığını (doğruluğunu) artırarak büyük verilerle çalışılsa bile hem hafızadan hem de zamandan tasarruf edilmiş olunacak.
> 
> Veri tekrarını önlemek için her veri türü için ayrı tablolar oluşturulup, bu tablolar birbiri ile ilişkilendirilmelidir. Böylece indexlemeye uygun hale gelen tablolar, sorgu işlemlerine çok daha hızlı yanıt verir.


Tablolarda ilişkilendirme yapılırken **key** kullanılarak yapılır. Bu key'ler sütunlarda kullanılır ve **Primary Key**, **Foreign Key**, **Super Key** gibi çeşitleri vardır. Bu tarz ilişkilendirmeler yapılırken diagramlar kullanılır.
- **Primary Key** : Tablodaki herhangi bir sütun primary key olarak atanırsa o sütundaki  veriler asla aynı olamaz yani tekrar eden değerler alamaz. Kısacası sütundaki her satırın kendine ait bir değeri olmalıdır. Bunun sebebi, veri tabanında aramalar yapıldığında veri tabanının ilk baktığı yer olmasıdır. Bundan dolayı aynı değerden bir ya da daha fazla olması   belirsizliğe sebep olur. Buna en güzel örnek T.C. kimlik numralarımızdır. Her vatandaşın kendine özel bir numarası bulunmaktadır.  
- **Foreign Key** : Bir veri tablosuna girilebilecek değerleri başka bir veri tablosundaki alanlarla ilişkilendirmeye yarar. Kısacası, başka bir tablonun birincil anahtarının bir diğer tablo içerisinde yer almasıdır. Foreign Key ile aslında veri tutarlılığı sağlanmış olur. İlişkili tabloda olmayan herhangi bir veri diğer tabloda yazılamayacak.
- **Unique Key** :  Tablodaki herhangi bir sütuna verilebilecek bu key ile o sütundaki verilerin benzersiz olmasını, aynı değerin tekrardan girilmesi engellenir. İşlevi Primary Key ile benzerlik taşısa da, en önemli farklılık Unique Key’in Null değeri alabilmesidir.
- **Composite Key** : Bazı durumlarda 1 tane Primary Key tek başına kullanmak yeterli olmayabilir. Birden fazla alanın birlikte Primary Key gerektiği durumlarda Primary Key olarak ayarlaması gerekir. Bu durumada Composite Key kullanılır. Genellikle tablolar arasında many to many ilişki olduğu zamanlar kullanılır.



## References

- [Microsoft Docs] 
- [GeeksforGeeks]

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)

   [MSSQL]: <https://www.microsoft.com/tr-tr/sql-server/sql-server-2019>
   [MYSQL]: <https://www.mysql.com/>
   [Oracle SQL]: <https://www.oracle.com/tr/database/technologies/appdev/sqldeveloper-landing.html>
   [PostgreSQL]: <https://www.postgresql.org/>
   [Microsoft Docs]: <https://docs.microsoft.com/en-us/sql/t-sql/data-types/data-types-transact-sql?view=sql-server-ver15>
   [GeeksforGeeks]: <https://www.geeksforgeeks.org/sql-tutorial/>
