<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet 
  version="1.0" 
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
  xmlns="http://www.w3.org/1999/xhtml">
  <xsl:template match="/" >
    <html>
    <body>
    <ul>
      <xsl:apply-templates>
        <xsl:sort select="TITRE" order="ascending" />
      </xsl:apply-templates>
    </ul>
    </body>
    </html>
  </xsl:template>

  <xsl:template match="FILM" >
    <li>
    La note moyenne du film <xsl:text> "</xsl:text><xsl:value-of select="TITRE" /><xsl:text>" </xsl:text> est <xsl:text>  </xsl:text><xsl:value-of select="round(sum(NOTES/NOTE)div(count(NOTES/NOTE)))" />
	</li>
  </xsl:template>

</xsl:stylesheet>
