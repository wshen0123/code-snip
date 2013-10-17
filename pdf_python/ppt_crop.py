#! /usr/bin/env python
from pyPdf import PdfFileWriter, PdfFileReader

out_pdf = PdfFileWriter()
in_pdf = []
in_pdf.append(PdfFileReader(file("6_1.pdf", "rb")))
in_pdf.append(PdfFileReader(file("6_2.pdf", "rb")))

for i in range(0, in_pdf[0].numPages):
    out_pdf.addPage(in_pdf[0].getPage(i))
    out_pdf.addPage(in_pdf[1].getPage(i))

outputStream = file("document-output.pdf", "wb")
out_pdf.write(outputStream)
outputStream.close()
