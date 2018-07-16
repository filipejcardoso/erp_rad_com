object FImportar: TFImportar
  Left = 0
  Top = 0
  Caption = 'IMPORTAR'
  ClientHeight = 569
  ClientWidth = 756
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = 18
  Font.Name = 'Calibri'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 18
  object Button1: TButton
    Left = 232
    Top = 388
    Width = 313
    Height = 25
    Caption = 'PRODUTOS'
    Enabled = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 232
    Top = 233
    Width = 313
    Height = 25
    Caption = 'CLIENTES'
    Enabled = False
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 232
    Top = 264
    Width = 313
    Height = 25
    Caption = 'FORNECEDORES'
    Enabled = False
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 232
    Top = 419
    Width = 313
    Height = 25
    Caption = 'OR'#199'AMENTOS'
    Enabled = False
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 232
    Top = 326
    Width = 313
    Height = 25
    Caption = 'VENDAS'
    Enabled = False
    TabOrder = 4
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 232
    Top = 202
    Width = 313
    Height = 25
    Caption = 'CAIXA'
    Enabled = False
    TabOrder = 5
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 232
    Top = 171
    Width = 313
    Height = 25
    Caption = 'USU'#193'RIOS'
    Enabled = False
    TabOrder = 6
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 232
    Top = 295
    Width = 313
    Height = 25
    Caption = 'MARCAS'
    Enabled = False
    TabOrder = 7
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 232
    Top = 357
    Width = 313
    Height = 25
    Caption = 'FECHAMENTOS'
    Enabled = False
    TabOrder = 8
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 656
    Top = 27
    Width = 75
    Height = 25
    Caption = 'Button10'
    Enabled = False
    TabOrder = 9
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 232
    Top = 503
    Width = 313
    Height = 25
    Caption = 'Button11'
    Enabled = False
    TabOrder = 10
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 240
    Top = 458
    Width = 305
    Height = 25
    Caption = 'Button12'
    Enabled = False
    TabOrder = 11
    OnClick = Button12Click
  end
  object Button13: TButton
    Left = 616
    Top = 312
    Width = 75
    Height = 25
    Caption = 'Button13'
    TabOrder = 12
    OnClick = Button13Click
  end
  object SQLConnection1: TSQLConnection
    DriverName = 'MySQL'
    Params.Strings = (
      'DriverUnit=Data.DBXMySQL'
      
        'DriverPackageLoader=TDBXDynalinkDriverLoader,DbxCommonDriver230.' +
        'bpl'
      
        'DriverAssemblyLoader=Borland.Data.TDBXDynalinkDriverLoader,Borla' +
        'nd.Data.DbxCommonDriver,Version=23.0.0.0,Culture=neutral,PublicK' +
        'eyToken=91d62ebb5b0d1b1b'
      
        'MetaDataPackageLoader=TDBXMySqlMetaDataCommandFactory,DbxMySQLDr' +
        'iver230.bpl'
      
        'MetaDataAssemblyLoader=Borland.Data.TDBXMySqlMetaDataCommandFact' +
        'ory,Borland.Data.DbxMySQLDriver,Version=23.0.0.0,Culture=neutral' +
        ',PublicKeyToken=91d62ebb5b0d1b1b'
      'GetDriverFunc=getSQLDriverMYSQL'
      'LibraryName=dbxmys.dll'
      'LibraryNameOsx=libsqlmys.dylib'
      'VendorLib=LIBMYSQL.dll'
      'VendorLibWin64=libmysql.dll'
      'VendorLibOsx=libmysqlclient.dylib'
      'HostName=localhost'
      'Database=loja'
      'User_Name=root'
      'Password=bidu1313'
      'MaxBlobSize=-1'
      'LocaleCode=0000'
      'Compressed=False'
      'Encrypted=False'
      'BlobSize=-1'
      'ErrorResourceFile=')
    Left = 40
    Top = 24
  end
  object SQLQuery1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 144
    Top = 24
  end
  object SQLQuery2: TSQLQuery
    Params = <>
    Left = 216
    Top = 24
  end
  object SQLQuery3: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 280
    Top = 24
  end
  object SQLQuery4: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 144
    Top = 88
  end
end
