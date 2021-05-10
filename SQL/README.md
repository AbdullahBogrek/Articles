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

## _T-SQL_

Transact-SQL yani T-SQL, Microsoft SQL Server veri tabanı için kullanılan sorgulama diline verilen isimdir. Microsoft kendi platformu için SQL üzerine yaptığı iyileştirmeleri standart haline getirmiş ve T-SQL ismini vermiştir. Transact-SQL‘in kısaltması olan T-SQL günümüz veritabanı yönetim ihtiyaçlarının tamamını karşılayabilecek yeterliliğe sahiptir. Fakat MYSQL, Oracle SQL gibi veri tabanlarında da aynı dil yapısı çeşitli farklılıklarla kullanılır. T-SQL ile veritabanı üzerinde işlem yapabilmek için SQL komutları "Data Manipulation Language-DML", "Data Definition Language-DDL" ve "Data Control Language-DCL" olarak üçe ayrılır.

## Refrecenses

- [Microsoft Docs] 

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)

   [MSSQL]: <https://www.microsoft.com/tr-tr/sql-server/sql-server-2019>
   [MYSQL]: <https://www.mysql.com/>
   [Oracle SQL]: <https://www.oracle.com/tr/database/technologies/appdev/sqldeveloper-landing.html>
   [PostgreSQL]: <https://www.postgresql.org/>
   [Microsoft Docs]: <https://docs.microsoft.com/en-us/sql/t-sql/data-types/data-types-transact-sql?view=sql-server-ver15>
