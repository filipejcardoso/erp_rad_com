object FGraficoVendas: TFGraficoVendas
  Left = 0
  Top = 0
  Caption = 'Gr'#225'fico de Vendas'
  ClientHeight = 685
  ClientWidth = 1370
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = 18
  Font.Name = 'Calibri'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  OnClose = FormClose
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 18
  object Chart1: TChart
    Left = 0
    Top = 104
    Width = 1370
    Height = 309
    Title.Font.Color = clBlack
    Title.Font.Height = -40
    Title.Font.Style = [fsBold]
    Title.Text.Strings = (
      'TChart')
    View3D = False
    Align = alClient
    TabOrder = 0
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series1: TBarSeries
      BarBrush.BackColor = clDefault
      BarPen.Width = 3
      ColorEachPoint = True
      Marks.Brush.Gradient.Colors = <
        item
          Color = clRed
        end
        item
          Color = 819443
          Offset = 0.067915690866510540
        end
        item
          Color = clYellow
          Offset = 1.000000000000000000
        end>
      Marks.Brush.Gradient.Direction = gdTopBottom
      Marks.Brush.Gradient.EndColor = clYellow
      Marks.Brush.Gradient.MidColor = 819443
      Marks.Brush.Gradient.StartColor = clRed
      Marks.Brush.Gradient.Visible = True
      Marks.Font.Color = 159
      Marks.Font.Name = 'Tahoma'
      Marks.Font.Style = [fsBold, fsItalic]
      Marks.Frame.Color = 33023
      Marks.RoundSize = 14
      Marks.Visible = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
  end
  object PanelOpcao: TPanel
    Left = 0
    Top = 0
    Width = 1370
    Height = 104
    Align = alTop
    TabOrder = 1
    object Label1: TLabel
      Left = 670
      Top = 11
      Width = 68
      Height = 18
      Caption = 'Data Inicial'
    end
    object Label2: TLabel
      Left = 830
      Top = 11
      Width = 61
      Height = 18
      Caption = 'Data Final'
    end
    object data_inicial: TDateTimePicker
      Left = 670
      Top = 35
      Width = 132
      Height = 31
      Date = 42217.857514675920000000
      Time = 42217.857514675920000000
      TabOrder = 0
    end
    object data_final: TDateTimePicker
      Left = 830
      Top = 35
      Width = 132
      Height = 31
      Date = 42235.857514675920000000
      Time = 42235.857514675920000000
      TabOrder = 1
    end
    object Button1: TButton
      Left = 994
      Top = 35
      Width = 189
      Height = 31
      Caption = 'FILTRAR'
      Default = True
      TabOrder = 2
      OnClick = Button1Click
    end
    object GroupBox1: TGroupBox
      Left = 15
      Top = 14
      Width = 634
      Height = 65
      Caption = 'Op'#231#245'es'
      TabOrder = 3
      object ComboPeriodo: TComboBox
        Left = 17
        Top = 24
        Width = 72
        Height = 26
        Style = csDropDownList
        ItemIndex = 0
        TabOrder = 0
        Text = 'Dia'
        Items.Strings = (
          'Dia'
          'M'#234's'
          'Ano')
      end
      object CheckConsumidor: TCheckBox
        Left = 304
        Top = 27
        Width = 169
        Height = 17
        Caption = 'APENAS CONSUMIDOR'
        TabOrder = 1
      end
      object CheckFinalizado: TCheckBox
        Left = 474
        Top = 27
        Width = 159
        Height = 17
        Caption = 'APENAS FINALIZADO'
        TabOrder = 2
      end
      object ComboAtendentes: TComboBox
        Left = 99
        Top = 24
        Width = 122
        Height = 26
        Style = csDropDownList
        ItemIndex = 0
        TabOrder = 3
        Text = 'Dia'
        Items.Strings = (
          'Dia'
          'M'#234's'
          'Ano')
      end
    end
    object CheckGrafico: TCheckBox
      Left = 1215
      Top = 42
      Width = 65
      Height = 17
      Caption = 'Grafico'
      Checked = True
      State = cbChecked
      TabOrder = 4
      OnClick = CheckGraficoClick
    end
    object CheckTabela: TCheckBox
      Left = 1294
      Top = 42
      Width = 76
      Height = 17
      Caption = 'Tabela'
      Checked = True
      State = cbChecked
      TabOrder = 5
      OnClick = CheckTabelaClick
    end
  end
  object StringGrid1: TStringGrid
    Left = 0
    Top = 413
    Width = 1370
    Height = 272
    Align = alBottom
    TabOrder = 2
    OnDrawCell = StringGrid1DrawCell
  end
  object SQLQuery1: TSQLQuery
    Params = <>
    Left = 1296
    Top = 328
  end
end
