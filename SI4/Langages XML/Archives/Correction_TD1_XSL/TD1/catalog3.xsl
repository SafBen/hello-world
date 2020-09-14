<?xml version="1.0" encoding="ISO-8859-1"?>
<!-- 
	XSLT pour CATALOG de CD
		auteur:PFZ
		version: 2007
		step: 2
-->
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<!-- Tableau filtré par prix -->
<xsl:template match="/">
  <html>
<head> <title> cd_catalog XSLT V2 </title> </head>
  <body>
    <h2>My CD Collection (version 2 vers HTML: for-each + if test)</h2>
    <table border="1">
    <tr bgcolor="#9acd32">
      <th align="left">Title</th>
      <th align="left">Artist</th>
    </tr>
    <xsl:for-each select="CATALOG/CD">
	<xsl:sort select="ARTIST"/>
	<xsl:if test="PRICE &gt; 10">
    <tr>
      <td><xsl:value-of select="TITLE"/></td>
      <td><xsl:value-of select="ARTIST"/></td>
    </tr>
	</xsl:if>
    </xsl:for-each>
    </table>
  </body>
  </html>
</xsl:template>

</xsl:stylesheet>
